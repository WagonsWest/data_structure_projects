#include "heap.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

heap::heap(int c) {
    size = 0;
    position = new int[c];
    min_heap = new heapNode*[c];
}

heap::~heap() {

}

void heap::setSize(int s) {
    size = s;
}

int heap::getSize() {
    return size;
}

void heap::insertNode(int v, double k) {
    min_heap[v] = new heapNode(v, k);
}

void heap::setPosition(int v) {
    position[v] = v;
}

void heap::swapNode(heapNode** a, heapNode** b) {
    heapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heap::heapify(int index) {
    int parent=index, left_child=2*index+1, right_child=2*index+2;
    
    if(left_child<size && min_heap[left_child]->getKey() < min_heap[parent]->getKey()) {
        parent = left_child;
    }
    if(right_child<size && min_heap[right_child]->getKey() < min_heap[parent]->getKey()) {
        parent = right_child;
    }

    if(parent!=index) {
        position[min_heap[parent]->getVertex()] = index;
        position[min_heap[index]->getVertex()] = parent;
        swapNode(&min_heap[parent], &min_heap[index]);

        heapify(parent);
    }
}

heapNode* heap::extractMin() {
    /*if(size == 0) {
        return NULL;
    }*/

    heapNode* min_node = min_heap[0];
    heapNode* temp_node = min_heap[size-1];
    min_heap[0] = temp_node;

    position[min_node->getVertex()] = size-1;
    position[temp_node->getVertex()] = 0;
    size -= 1;

    heapify(0);
    return min_node;
}

void heap::modifyKey(int v, double k) {
    int index = position[v];
    min_heap[index]->setKey(k);
    while (index && min_heap[index]->getKey() < min_heap[(index-1)/2]->getKey()) {
        position[min_heap[index]->getVertex()] = (index-1)/2;
        position[min_heap[(index-1)/2]->getVertex()] = index;
        swapNode(&min_heap[index], &min_heap[(index-1)/2]);
    
        index = (index-1)/2;
    }
}

bool heap::inHeap(int v) {
    if(position[v] < size)
        return true;
    return false;
}