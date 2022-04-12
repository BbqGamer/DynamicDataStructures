#include "LinkedList.h"

void LinkedList::insertNode(Person p) {
    LinkedListNode *node = new LinkedListNode(p);
    if (head == nullptr || head->getData() > p) {
        head = node;
    } else {
        LinkedListNode *current = head;
        while (current->getNext() != nullptr) {
            if(current->getNext()->getData() > p) {
                node->setNext(current->getNext());
                current->setNext(node);
                return;
            }
            current = current->getNext();
        }
        current->setNext(node);
    }
}

Person LinkedList::search(int index) {
    LinkedListNode *current = head;
    while (current != nullptr) {
        if (current->getData().getIndex() == index) {
            return current->getData();
        }
        current = current->getNext();
    }
    return Person();
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