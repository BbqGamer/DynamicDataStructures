#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Person.h"

class LinkedListNode {

    LinkedListNode *next;
    Person data;

public:
    LinkedListNode(): next(nullptr), data(Person()) {};
    LinkedListNode(Person p): next(nullptr), data(p) {};

    Person getData();
    LinkedListNode* getNext();
    void setNext(LinkedListNode* node);
};


class LinkedList {
    public: LinkedListNode* head;
    LinkedList(): head(nullptr) {};
    ~LinkedList();

    void insertNode(Person p);
    Person search(int index);
    void removeNode(int index);
};

#endif