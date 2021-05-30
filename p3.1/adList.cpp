#include "adList.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

adList::adList() {
    head = NULL;
    degree = 0;
}

adList::~adList() {
    alNode* current = head;
    while( current != NULL ) {
        alNode* next_node = current->getNext();
        delete current;
        current = next_node;
    }
    head = NULL;
}

alNode* adList::getHead() {
    return head;
}

void adList::setHead(alNode* hd) {
    head = hd;
    if(hd != NULL) {
        degree += 1;
    } else {
        degree = 0;
    }
}

bool adList::adjacent_withE(int v, double w) {
    alNode* temp = head;
    while(temp!=NULL) {
        if(temp->getVertex()==v) {
            if(temp->getWeight()==w)
                return true;

            return false;
        }
        temp = temp->getNext();
    }
    return false;
}

bool adList::erase(int v) {
    alNode* temp = head;

    if(temp == NULL)
        return false;

    if(temp->getVertex() == v) {
        head = temp->getNext();
        degree -= 1;
        return true;
    }

    while(temp->getNext()!=NULL) {
        if(temp->getNext()->getVertex() == v) {
            temp->setNext(temp->getNext()->getNext());
            degree -= 1;
            return true;
        }
        
        temp = temp->getNext();
    }
    return false;
}

int adList::getDegree() {
    return degree;
}