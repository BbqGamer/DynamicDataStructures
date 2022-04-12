#include "LinkedList.h"

// void LinkedList::insertNode(Person p) {
//     LinkedListNode *node = new LinkedListNode(p);
//     if (head == nullptr) {
//         head = node;
//     } else {
//         LinkedListNode *current = head;
//         while (current->getNext() != nullptr) {
//             current = current->getNext();
//         }
//         current->setNext(node);
//     }
// }

Person LinkedListNode::getData() {
    return data;
}

LinkedListNode* LinkedListNode::getNext() {
    return next;
}

void LinkedListNode::setNext(LinkedListNode* node) {
    next = node;
}