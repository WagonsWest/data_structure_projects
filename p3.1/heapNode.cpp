#include "heapNode.h"

using namespace std;

heapNode::heapNode(int v, double k) {
    vertex = v;
    key = k;
}

heapNode::~heapNode() {

}

int heapNode::getVertex() {
    return vertex;
}

void heapNode::setKey(double k) {
    key = k;
}

double heapNode::getKey() {
    return key;
}