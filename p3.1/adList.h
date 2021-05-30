#ifndef ADLIST
#define ADLIST

#include "adNode.h"
using namespace std;

class adList {
    private:
        alNode* head;
        int degree;

    public:
        adList();
        ~adList();

        alNode* getHead();
        void setHead(alNode* hd);
        bool adjacent_withE(int v, double w);

        bool erase(int v);
        int getDegree();

};

#endif