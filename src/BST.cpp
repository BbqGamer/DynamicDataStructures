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