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
    if (root == nullptr) {
        root = new BSTNode(p);
    } else {
        BSTNode* current = root;
        while (true) {
            if (current->getData() > p) {
                if (current->getLeft() == nullptr) {
                    current->setLeft(new BSTNode(p));
                    break;
                } else {
                    current = current->getLeft();
                }
            } else {
                if (current->getRight() == nullptr) {
                    current->setRight(new BSTNode(p));
                    break;
                } else {
                    current = current->getRight();
                }
            }
        }
    }
}