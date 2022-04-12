#include "BST.h"

BSTNode* BST::getRoot() {
    return root;
}

BSTNode* BSTNode::getRight() {
    return right;
}

BSTNode* BSTNode::getLeft() {
    return left;
}

Person BSTNode::getData() {
    return data;
}

void BSTNode::setLeft(BSTNode* node) {
    left = node;
}

void BSTNode::setRight(BSTNode* node) {
    right = node;
}

void BST::insert(Person p) {
    BSTNode* newNode = new BSTNode(p);
    if (root == nullptr) {
        root = newNode;
    } else {
        BSTNode* current = root;
        while (true) {
            if (current->getData() > p) {
                if (current->getLeft() == nullptr) {
                    current->setLeft(newNode);
                    break;
                } else {
                    current = current->getLeft();
                }
            } else {
                if (current->getRight() == nullptr) {
                    current->setRight(newNode);
                    break;
                } else {
                    current = current->getRight();
                }
            }
        }
    }
}