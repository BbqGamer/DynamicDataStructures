#include "LinkedList.h"

void LinkedList::insert(Person p) {
    LinkedListNode** tracer = &head;
    while(*tracer != nullptr && (*tracer)->data.getIndex() < p.getIndex()) { 
        tracer = &((*tracer)->next);
    }
    LinkedListNode* newNode = new LinkedListNode(p);
    newNode->next = *tracer;
    *tracer = newNode;
}

Person LinkedList::search(int index) {
    LinkedListNode *current = head;
    while (current != nullptr) {
        if (current->getData().getIndex() == index) {
            return current->getData();
        }
        current = current->getNext();
    }
    throw std::out_of_range("Index not found in Linked List");
}

void LinkedList::remove(int index) {
    LinkedListNode *current = head;
    LinkedListNode *previous = nullptr;
    while (current != nullptr) {
        if (current->getData().getIndex() == index) {
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            delete current;
            return;
        }
        previous = current;
        current = current->getNext();
    }
    throw std::out_of_range("Index not found in Linked List");
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