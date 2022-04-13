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

void BSTNode::setData(Person p) {
    data = p;
}

void BSTNode::setLeft(BSTNode* node) {
    left = node;
}

void BSTNode::setRight(BSTNode* node) {
    right = node;
}

int BSTNode::getHeight() {
    return height;
}

void BSTNode::setHeight(int _height) {
    height = _height;
}

BSTNode* BSTNode::findMin() {
    BSTNode* current = this;
    while(current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
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

Person BST::search(int index) {
    BSTNode* current = root;
    while (current != nullptr) {
        if (current->getData().getIndex() == index) {
            return current->getData();
        }
        if (current->getData().getIndex() > index) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }
    throw std::out_of_range("Index not found in BST");
}

void BST::remove(int index) {
    root = removeFromSubtree(root, index);
}

BSTNode* removeFromSubtree(BSTNode* root, int index) {
    if (root == nullptr) {
        throw std::out_of_range("Index not found in BST");
    }
    if (root->getData().getIndex() > index) {
        root->setLeft(removeFromSubtree(root->getLeft(), index));
    } else if (root->getData().getIndex() < index) {
        root->setRight(removeFromSubtree(root->getRight(), index));
    } else {
        if (root->getLeft() == nullptr && root->getRight() == nullptr) {
            delete root;
            return nullptr;
        } else if (root->getLeft() == nullptr) {
            BSTNode* temp = root->getRight();
            delete root;
            return temp;
        } else if (root->getRight() == nullptr) {
            BSTNode* temp = root->getLeft();
            delete root;
            return temp;
        } else {
            BSTNode* temp = root->getRight()->findMin();
            root->setData(temp->getData());
            root->setRight(removeFromSubtree(root->getRight(), temp->getData().getIndex()));
        }
    }
    return root;
}

void deleteSubtree(BSTNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());
    delete node;
}

BST::~BST() {
    deleteSubtree(root);
}