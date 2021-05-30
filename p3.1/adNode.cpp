#include "adNode.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

alNode::alNode(const int v, const double w) {
    vertex = v;
    weight = w;
    next_node = NULL;
}

alNode::~alNode() {
    
}

void alNode::setNext(alNode* nxt) {
    next_node = nxt;
}

alNode* alNode::getNext() {
    return next_node;
}

int alNode::getVertex() {
    return vertex;
}

double alNode::getWeight() {
    return weight;
}