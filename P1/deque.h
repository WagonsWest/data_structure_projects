#ifndef DEQUE
#define DEQUE

//#include <iostream>
#include "node.h"

class deque {
    private:
        int count;
        node *head;
        node *tail;

    public:
        deque();
        ~deque();

        void push_front(std::string n, std::string u);
        void push_back(std::string n, std::string u);

        void pop_front();
        void pop_back();

        void clear();

        void size();
        void front();
        void back();
        void empty();

        void find(std::string name);
        void print();

};

#endif
