#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include <string>
#include <vector>
#include <stdexcept>
#include <utility>

using std::string;
using std::vector;
using std::pair;

class MaxHeap {
private:
    //Create a vector to store the heap
    vector<pair<string, int>> heap;

    //Mention functions necessary for heap
    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;
    void bubbleup(int index);
    void bubbledown(int index);

public:
    MaxHeap();
    void insert(const string& key, int value);
    bool empty() const;
    pair<string, int> getMax() const;
    
};
#endif

