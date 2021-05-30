#ifndef BHEAP
#define BHEAP
#include "heapNode.h"

using namespace std;

class heap {
    private:
        int size;
        int* position;
        heapNode** min_heap;

    public:
        heap(int c);
        ~heap();

        void insertNode(int v, double k);
        void setPosition(int v);
        void swapNode(heapNode** a, heapNode** b);
        void setSize(int s);
        int getSize();

        void heapify(int index);
        heapNode* extractMin();
        void modifyKey(int v, double k);
        bool inHeap(int v);
};

#endif