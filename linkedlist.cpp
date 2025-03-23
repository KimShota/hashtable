//============================================================================
// Author       : Shota Matsumoto
// Version      : 1.0
// Date Created : 20-11-2024
// Date Modified: 22-11-2024
// Description  : Singly Linked-List implementation in C++
//============================================================================

#include "linkedlist.h"
#include<iostream>
using namespace std;

//Constructor
Node::Node(string key, int value){
    //Initialize key
    this->key = key;
    //Initialize value
    this->value = value;
    //Initialize next pointer to nullptr
    this->next = nullptr;
}

//Getter function to access key
string Node::getKey(){
    //Return key
    return key;
}

//Getter function to access value
int Node::getValue(){
    //Return value
    return value;
}

//Modifier function to update the key
void Node::setKey(string key){
    //Set the key
    this->key = key;
}

//Modifier fucntion to update the value
void Node::setValue(int value){
    //Set the value
    this->value = value;
}

//=================================================
//Constructor
LinkedList::LinkedList(){
    //Initialize head pointer to nullptr
    head = nullptr;
    //Initialize size to 0
    size = 0;
}

//Deconstructor
LinkedList::~LinkedList(){
    //Call clear function to remove all the nodes
    clear();
}

//Function to check if the list is empty or not
bool LinkedList::empty() const{
    return head == nullptr;
}

//Function to get the size of the list
unsigned int LinkedList::getSize() const{
    return size;
}

//Function to insert a new node with key and value
void LinkedList::insert (string key, int value){
    //Search for the node that has the same key as the user input by assining find() function to v node
    Node* v = find(key);
    //If the node with the same key already exists, then
    if (v){
        //Update its value (frequency)
        v->setValue(v->getValue() + value);
    } else{ //If the key does not exist, then
        //Create a new node called u with new key and value
        Node* u = new Node(key, value);
        //Add the new node to the beginning of the linkedlist
        u->next = head;
        //Make head pointer point to the new node
        head = u;
        //Increment the size by one
        size++;
    }
}

//Function to search for the node with the same key
Node* LinkedList::find (string key){
    //Create a node called v to start traversing from the head
    Node* v = head;
    //Continue looping while v exists
    while (v){
        //If the key of the node is same as the user input key, then
        if (v->getKey() == key){
            //Return the node v
            return v;
        }
        //Move to the next node
        v = v->next;
    }
    //Return nullptr if key is not found 
    return nullptr;
}

//Function to remove all the nodes
void LinkedList::clear(){
    //Create a node called v to start traverse from the head
    Node* v = head;
    //Continue looping while v exists
    while (v){
        //Create the node called u that v points to
        Node* u = v->next;
        //Delete the node that v points to
        delete v;
        //Move to the next node
        v = u;
    }
    //Make head pointer point to nullptr
    head = nullptr;
    //Set size to 0
    size = 0;
}
