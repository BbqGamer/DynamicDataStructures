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

Person LinkedListNode::getData() {
    return data;
}

LinkedListNode* LinkedListNode::getNext() {
    return next;
}

void LinkedListNode::setNext(LinkedListNode* node) {
    next = node;
}