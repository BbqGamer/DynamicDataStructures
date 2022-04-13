#include "AVL.h"

BSTNode *leftRotate(BSTNode *x)
{
    BSTNode *y = x->getRight();
    BSTNode *T2 = y->getLeft();
 
    y->setLeft(x);
    x->setRight(T2);
 
    x->setHeight(std::max(x->getLeft()->getHeight(),   
                    x->getRight()->getHeight()) + 1);

    y->setHeight(std::max(y->getLeft()->getHeight(),
                    y->getRight()->getHeight()) + 1);
 
    return y;
}

BSTNode *rightRotate(BSTNode *y)
{
    BSTNode *x = y->getLeft();
    BSTNode *T2 = x->getRight();
 
    x->setRight(y);
    y->setLeft(T2);
 
    y->setHeight(std::max(y->getLeft()->getHeight(),   
                    y->getRight()->getHeight()) + 1);

    x->setHeight(std::max(x->getLeft()->getHeight(),
                    x->getRight()->getHeight()) + 1);
 
    return x;
}

void AVL::setRoot(BSTNode* node) {
    BST::setRoot(node);
}