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
