#include <iostream>
#include "deque.h"

deque::deque() {
    count = 0;
    head = NULL;
    tail = NULL;
}

deque::~deque() {
    while (head != NULL) {
        count --;
        node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

void deque::push_front(std::string n, std::string u) {
    if (head == NULL) {
        head = new node;
        head->url_name = n;
        head->url = u;
        tail = head;
        count++;

        std::cout << "success" << std::endl;
    }
    else {
        node *nnode = new node;
        nnode->url_name = n;
        nnode->url = u;
        head->prev = nnode;
        nnode->next = head;
        head = nnode;
        count++;

        std::cout << "success" << std::endl;
    }
}

void deque::push_back(std::string n, std::string u) {
    if (tail == NULL) {
        tail = new node;
        tail->url_name = n;
        tail->url = u;
        head = tail;
        count++;

        std::cout << "success" << std::endl;
    }
    else {
        node *nnode = new node;
        nnode->url_name = n;
        nnode->url = u;
        tail->next = nnode;
        nnode->prev = tail;
        tail = nnode;
        count++;

        std::cout << "success" << std::endl;
    }
}

void deque::pop_front() {
    if (head == NULL) {
        std::cout << "failure" << std::endl;
    }
    else if (head == tail) {
        node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        count --;

        std::cout << "success" << std::endl;
    }
    else {
        node *temp = head;
        head = head->next;
        delete temp;
        count --;

        std::cout << "success" << std::endl;
    }
}

void deque::pop_back() {
    if (tail == NULL) {
        std::cout << "failure" << std::endl;
    }
    else if (head == tail) {
        node *temp = tail;
        head = NULL;
        tail = NULL;
        delete temp;
        count --;

        std::cout << "success" << std::endl;
    }
    else {
        node *temp = tail;
        tail = tail->prev;
        delete temp;
        count --;

        std::cout << "success" << std::endl;
    }
}

void deque::size() {
    std::cout << "size is " << count << std::endl;
}

void deque::front() {
    if (head == NULL) {
        std::cout << "failure" << std::endl;
    }
    else {
        std::cout << "front is " << head->url_name << " " << head->url << std::endl;
    }
}

void deque::back() {
    if (tail == NULL) {
        std::cout << "failure" << std::endl;
    }
    else {
        std::cout << "back is " << tail->url_name << " " << tail->url << std::endl;
    }
}

void deque::empty() {
    if (head == NULL) {
        std::cout << "empty 1" << std::endl;
    }
    else {
        std::cout << "empty 0" << std::endl;
    }
}

void deque::clear() {
    while (head != NULL) {
        count--;
        node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    std::cout << "success" << std::endl;
}

void deque::find(std::string name) {
    node *ptr = new node;
    ptr = head;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->url_name == name) {
            std::cout << "found " << ptr->url_name << " " << ptr->url << std::endl;
            found = 1;
            break;
        }

        ptr = ptr->next;
    }
    if (!found) {
        std::cout << "not found " << name << std::endl;
    }
}

void deque::print() {
    if (head != NULL) {
        node *prt_ptr = tail;
        while (prt_ptr != NULL) {
            std::cout << prt_ptr->url_name << " " << prt_ptr->url << std::endl;
            
            prt_ptr = prt_ptr->prev;
            /*if (tail->prev != NULL) {
                tail = tail->prev;
            }
            else {
                tail = prt_ptr;
                delete prt_ptr;
                break;
            }*/
        }
    }
}