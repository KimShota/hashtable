#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;

//Constructor
HashTable::HashTable(int capacity){
    //Set the capacity of the hash table
    this->capacity = capacity;
    //Initialize collisions to 0
    collisions = 0;
    //Initialize unique_words to 0
    unique_words = 0;
    //Initialize total_words to 0
    total_words = 0;
    //Initialize hash_code_function to set the function to the default one
    hash_code_function = 0;
    
    //Allocate memory space for the buckets based upon capacity
    buckets = new LinkedList[capacity];
}

//Function that checks whether user input is in the range or not
void HashTable::SetHashFunction(int userIndex){
    if (userIndex >= 0 && userIndex <= 5){
        hash_code_function = userIndex;
        cout << "Your hash function is now set to " << userIndex << endl;
    } else {
        cout << "Your input is invalid. Please enter valid input ranging between 0 and 5." << endl;
    }
}

//Function to let user choose which hash function they want to use
unsigned long HashTable::hashCode(string key){
    switch (hash_code_function){
        case 0:
            return PolyCyclicHash(key);
        case 1:
            return polynomialHash(key);
        case 2:
            return SummationHash(key);
        case 3:
            return CycleShiftHash(key);
        case 4:
            return SumCyclicHash(key);
        case 5:
            return SumPolyHash(key);
        default:
            return PolyCyclicHash(key);
    }
}

//Function with polynomial hashing techniques
unsigned int HashTable::polynomialHash(const string& key){
    //Initialize myHashCode to 0
    unsigned int myHashCode = 0;
    //Initialize a to 37
    unsigned int a = 37;
    //Initialize b to 1
    unsigned int b = 1;
    
    //Iterate through each character in the given word
    for (std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Cast each char into int and multiply hash code by a
        myHashCode += ((unsigned int) *iterator) * b;
        //Iteratively raise the power of a
        b = a * b;
    }
    
    //Initialize x to 31
    const unsigned int x = 31;
    //Initialize y to 7
    const unsigned int y = 7;
    
    //Get the hash code by making it fall into the range between 0 and capacity - 1
    unsigned int finalHashCode = ((x * myHashCode + y) % capacity);
    
    //Return hash code
    return finalHashCode;
}

//Cycle shift function to generate the hash code using bitwise operations
unsigned int HashTable::CycleShiftHash(const std::string& key){
    //Initialize hash code to 0
    unsigned int h = 0;
    
    //Iterate through each character in the string using iterator
    for (std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Dereference iteratorn to get the character
        char ch = *iterator;
        //Shift hash code 5 bits to the left and 27 bits to the right
        h = (h << 5) | (h >> 27);
        //Combine the results using bitwise or operator
        h ^= ch;
    }
    
    //Use Division method for compress function
    unsigned int hashCode = h % capacity;
    
    //Return the hash code
    return hashCode;
}

//Function using Summation hashing techniques
unsigned int HashTable::SummationHash(const std::string& key){
    //Initialize hash code to 0
    unsigned int myHashCode = 0;
    
    //Iterate through each character in the given word and take the sum after casting each of them into integer
    for (std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Cast char into int and sum them up (ASCII value)
        myHashCode += (unsigned int) *iterator;
    }
    
    //Take the remainder by using modulo to make hash code fall into the range between 0 and capacity - 1
    unsigned int hashCode = myHashCode % capacity;
    
    //Return hash code
    return hashCode;
}

//Function with both polynomial and cycle shift hashing techniques
unsigned int HashTable::PolyCyclicHash(const std::string& key){
    //Initialize hash code to 0
    unsigned int myHashCode = 0;
    //Initialize a to 39
    unsigned int a = 39;
    //Initialize b to 1
    unsigned int b = 1;
    
    //Iterate through each character in the given word
    for (std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Sum up the result of hash codes multiplied by b
        myHashCode += ((unsigned int) *iterator) * b;
        //Iteratively raise the power of a
        b = a * b;
    }
    
    //Initialize hash code to 0
    unsigned int finalHash = 0;
    //Store the result from polynomial hashing phase
    unsigned int polyHash = myHashCode;
    
    //Iterate through each bit in the polyHash
    for (unsigned int i = 0; i < sizeof(polyHash) * 8; i++){
        //Store each bit
        unsigned int bit = (polyHash >> i) & 1;
        //Shift hash code 5 bits to the left and 27 bits to the right
        finalHash = (finalHash << 5) | (finalHash >> 27);
        //Combine the results using XOR operator
        finalHash ^= bit;
    }
    
    //Initialize x to 31
    const unsigned int x = 31;
    //Initialize y to 3
    const unsigned int y = 3;
    //Take the remainder by using modulo to make hash code fall into the range between 0 and capacity - 1
    unsigned int hashCode = ((finalHash * x + y) % capacity);
    
    //Return hash code
    return hashCode;
}

//Hash Function with summation and cycle shift hashing techniques
unsigned int HashTable::SumCyclicHash(const std::string& key){
    //Initialize hash code to 0
    unsigned int myHashCode = 0;
    //Iterate through each character in the given word
    for (std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Sum all the ASCII values from each character
        myHashCode += (unsigned int) *iterator;
    }
    
    //Initialize hash code to 0
    unsigned int finalHash = 0;
    //Store the hash code from the summation result to sumResult
    unsigned sumResult = myHashCode;
    
    //Iterate through each bit
    for (unsigned int i = 0; i < sizeof(sumResult) * 8; ++i){
        //Store each bit
        unsigned int bit = (sumResult >> i) & 1;
        //Shift hash code by 5 bits to the left and 27 bits to the right
        finalHash = (finalHash << 5) | (finalHash >> 27);
        //Combine the results using XOR operator
        finalHash ^= bit;
    }
    
    //Use division method for compression function
    unsigned int hashCode = finalHash % capacity;
    
    //Return the hash code
    return hashCode;
}

//Function with summation and polynomial techniques
unsigned int HashTable::SumPolyHash(const std::string& key){
    //Initialize myHashCode to 0
    unsigned int myHashCode = 0;
    
    //Iterate through each character in the given word
    for(std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Sum all the ASCII values from each character
        myHashCode += (unsigned int) *iterator;
    }
    
    //Initialize polyHash to 0
    unsigned int polyHash = 0;
    //Initialize a to 33
    unsigned int a = 33;
    //Initialize b to 1
    unsigned int b = 1;
    
    //Iterate through each character within the given word
    for (std::string::const_iterator iterator = key.begin(); iterator != key.end(); ++iterator){
        //Add hash code to myHashCode and multiply it by b each time
        polyHash += ((unsigned int) *iterator + myHashCode) * b;
        //Iteratively raise the power of a
        b = a * b;
    }
    
    //Obtain the hash code using division method
    unsigned int hashCode = polyHash % capacity;
    
    //Return the hash code
    return hashCode;
}

//Function to get the number of collisions
unsigned int HashTable::getCollisions(){
    //Return the number of collisions
    return collisions;
}

//Function to get the number of unique words
unsigned int HashTable::getUniqueWords(){
    //Return the number of unique words
    return unique_words;
}

//Function to get the total number of words
unsigned int HashTable::getTotalWords(){
    //Return the total number of words
    return total_words;
}

//Fucntion to import the file
void HashTable::import(string path) {
    //Open the file
    ifstream infile(path);
    
    //If the file cannot be opened, then display an error message
    if (!infile.is_open()) {
        cerr << "This file cannot be opened. Please try again." << endl;
        return;
    }

    //Declare line and word as strings
    string line, word;
    
    //Define punctuations as string and set those punctuations that you want to remove 
    const string punctuations = ".,\"!?;“”‘’";
    
    //Read the file
    while (getline(infile, line)) {
        //Iterate through each character in a line
        for (string::iterator iterator = line.begin(); iterator != line.end(); ++iterator){
            //Make the highercase to the lowercase by using tolower function
            *iterator = tolower(*iterator);
        }

        //Create a stringstream object called LS
        stringstream LS(line);
        
        //Extract each word and store them into word
        while (LS >> word){
            size_t beginning = 0;
            size_t end = word.length() - 1;

            //If the character at the beginning of the word is a punctuation, then
            while (beginning < word.length() && punctuations.find(word[beginning]) != string::npos){
                //Increment beginning by one to remove the punctuation
                beginning++;
            }

            //If the character at the end of the word is a punctuation, then
            while (end >= beginning && punctuations.find(word[end]) != string::npos){
                //Decrement end by one to remove the punctuation
                end--;
            }

            //Extract the only desired portion of the word excluding punctuations
            word = word.substr(beginning, end - beginning + 1);
            
            //If the word is not empty, then
            if (!word.empty()){
                //Insert the word into hash table by calling insert function
                insert(word);
            }
        }
    }
    
    //Close the file
    infile.close();
    
    //Display the message saying Done! and the outcomes
    cout << "Done!" << endl;
    cout << "The number of collisions is: " << collisions << endl;
    cout << "The number of unique words is: " << unique_words << endl;
    cout << "The total number of words is: " << total_words << endl;
}

//Function to insert the word into hash table
void HashTable::insert(string word){
    unsigned int index = hashCode(word);
    Node* sameWord = buckets[index].find(word);
    
    //If the same word already exists, then
    if (sameWord){
        //Increase the frequency of the word by one by using getter and setter funciton
        sameWord->setValue(sameWord->getValue() + 1);
        //Insert the word and its frequency into the heap
        maxHeap.insert(word, sameWord->getValue());
    } else{ //If the word does not exist in the bucket,
        //Insert the word into the bucket and increase the frequency by one by using insert method of the linkedlist class
        buckets[index].insert(word, 1);
        //Increment the number of unique words
        unique_words++;
        //If there are more than one words in the same bucket, then
        if (buckets[index].getSize() > 1){
            //Increment the number of collisions by one
            collisions++;
        }
        //Insert the word into heap
        maxHeap.insert(word, 1);
    }
    //Increment the total number of words
    total_words++;
}

//Function to find the frequency of the given word
int HashTable::find_freq(string word){
    //Get the index by hashing the word
    unsigned int index = hashCode(word);
    //Search for the word at the given index by using find method of the linkedlist, and if it is found then return the pointer to the node that contains the word and the value
    Node* inputWord = buckets[index].find(word);
    //If the word is found then return the value of the node. Otherwise, return 0.
    return inputWord ? inputWord->getValue() : 0;
}

//Destructor
HashTable::~HashTable(){
    //Iterate through each bucket using for loop
    for (int i = 0; i < capacity; i++){
        //Remove linkedlists in each bucket
        buckets[i].clear();
    }
    //Deallocate the memory space
    delete [] buckets;
}

//Function to return the word with the highest frequency
pair<string, int> HashTable::find_Max() {
    //If the heap is empty then display an error message
    if (maxHeap.empty()){
        throw std::runtime_error("There is currently no words in the hash table");
    }
    //Return the word with the highest frequency 
    return maxHeap.getMax();
}
