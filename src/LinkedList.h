#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Person.h"
#include "TestSubject.h"

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


class LinkedList: public TestSubject {
    LinkedListNode* head;
    
    public:
    
    LinkedList(): head(nullptr) {};
    ~LinkedList();

    LinkedListNode* getHead();

    void insert(Person p);
    Person search(int index);
    void remove(int index);

    std::string getStructureName() {return "LinkedList";};
};

#endif