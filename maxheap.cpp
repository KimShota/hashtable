#include "maxheap.h"

//Constructor
MaxHeap::MaxHeap() {}

//Function to insert an entry with the given key and value
void MaxHeap::insert(const string& key, int value){
    //Insert the entry at the rear of the heap
    heap.push_back({key, value});
    //Apply up heap bubbling method by calling bubbleup function
    bubbleup(heap.size() - 1);
}

//Function to return the word with the highest frequency
pair<string, int> MaxHeap::getMax() const{
    //If the heap is empty, then
    if (heap.empty()){
        //Display an error message
        throw std::runtime_error("There is currehtly no words in the hash table");
    }
    //Return the entry at the root of the heap
    return heap.front();
}

//Function to check whether the heap is empty or not
bool MaxHeap::empty() const{
    return heap.empty();
}

//Function to return the index of the parent node of the node at the given index
int MaxHeap::parent(int index) const{
    return (index - 1) / 2;
}

//Function to return the index of the left child of the node at the given index
int MaxHeap::left(int index) const{
    //Return the index of the left child that is always located at the index 2*index + 1
    return index * 2 + 1;
}

//Function to return the index of the right child of the node at the given index
int MaxHeap::right(int index) const{
    //Return the index of the left child that is always located at the index 2*index + 2
    return index * 2 + 2;
}

//Function to move the element at the given index up to its correct position in order to maintain the heap property
void MaxHeap::bubbleup(int index){
    //Keep moving the element up as long as its frequnecy is larger than the frequency of the parent node
    while (index > 0 && heap[index].second > heap[parent(index)].second) {
        //Swap the element with the parent
        std::swap(heap[index], heap[parent(index)]);
        //Move up to the parent node
        index = parent(index);
    }
}

//Function to move the element at the given index down to its correct position to maintain the heap property
void MaxHeap::bubbledown(int index){
    while (true) {
        //Index of the left child
        int leftIndex = left(index);
        //Index of the right child
        int rightIndex = right(index);
        //Assume that the provided node has the largest frequency
        int largest = index;
        
        //If there is a left child and it has a greater frequnecy than the one of the given node
        if (leftIndex < heap.size() && heap[leftIndex].second > heap[largest].second) {
            //Assign leftIndex to largest
            largest = leftIndex;
        }
        //If there is a right child and it has a greater frequency than the one of the given node
        if (rightIndex < heap.size() && heap[rightIndex].second > heap[largest].second) {
            //Assign rightIndex to largest
            largest = rightIndex;
        }
        //If the given index is the largest, then break the loop
        if (largest == index) {
            break;
        }
        
        //Swap the given node with the child node that has the largest frequency
        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}
