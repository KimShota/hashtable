#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#include <string>
#include "linkedlist.h"
#include "maxheap.h"
using std::string;

class HashTable
{
    private:
        LinkedList *buckets;                        // Array of Buckets (chains)
        unsigned int capacity;                        // Total Capacity of HashTable
        unsigned int collisions;                     // Total Number of Collisions
        unsigned int unique_words;                    // Number of unique words in the hashtable
        unsigned int total_words;                    // Total number of words in the hashtable
        int hash_code_function;                        // Selected Hash_code function
    
    
        //Six different hash functions
        unsigned int polynomialHash(const std::string& key);
        unsigned int CycleShiftHash(const std::string& key);
        unsigned int SummationHash(const std::string& key);
        unsigned int PolyCyclicHash(const std::string& key);
        unsigned int SumCyclicHash(const std::string& key);
        unsigned int SumPolyHash(const std::string& key);
    
    public:
        HashTable(int capacity);
        unsigned long hashCode(string key);
        unsigned int getCollisions();
        unsigned int getUniqueWords();
        unsigned int getTotalWords();
        void import(string path);
        void insert(string word);
        int find_freq(string word);                        //return the frequency of a word
        ~HashTable();
        void SetHashFunction(int userIndex);
    
        //Create an object of the class MaxHeap
        MaxHeap maxHeap;
        pair<string, int> find_Max();
    
};
#endif
