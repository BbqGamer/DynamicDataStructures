#include "LinkedList.h"

void LinkedList::insert(Person p) {
    LinkedListNode** tracer = &head;
    while(*tracer && (*tracer)->data.getIndex() < p.getIndex()) { 
        tracer = &((*tracer)->next);
    }
    LinkedListNode* newNode = new LinkedListNode(p);
    newNode->next = *tracer;
    *tracer = newNode;
}

Person LinkedList::search(int index) {
    LinkedListNode *current = head;
    while (current) {
        if (current->data.getIndex() == index) {
            return current->data;
        }
        current = current->next;
    }
    throw std::out_of_range("Index not found in Linked List");
}

void LinkedList::remove(int index) {
    LinkedListNode** tracer = &head;
    LinkedListNode* old;
    bool present = false;

    while(*tracer && !(present=((*tracer)->data.getIndex() == index))) { 
        tracer = &((*tracer)->next);
    }

    if(present) {
        old = *tracer;
        *tracer = (*tracer)->next;
        delete old;
    } else {
        throw std::out_of_range("Index not found in Linked List");
    }
}

LinkedListNode* LinkedList::getHead() {
    return head;
}

Person LinkedListNode::getData() {
    return data;
}

LinkedListNode* LinkedListNode::getNext() {
    return next;
}

void LinkedListNode::setNext(LinkedListNode* node) {
    next = node;
}

LinkedList::~LinkedList() {
    LinkedListNode *current = head;
    while (current != nullptr) {
        LinkedListNode *next = current->getNext();
        delete current;
        current = next;
    }
}