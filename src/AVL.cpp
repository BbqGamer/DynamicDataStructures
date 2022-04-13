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

int getBalanceFactor(BSTNode *node)
{
    if (node == nullptr)
        return 0;
    return height(node->getLeft()) - height(node->getRight());
}

void AVL::insert(Person p) {
    BSTNode* ptr = insertToSubtree(this->getRoot(), p);
    setRoot(ptr);
}

BSTNode* insertToSubtree(BSTNode* node, Person p)
{
    if (node == nullptr)
        return(new BSTNode(p));
 
    if (node->getData() > p)
        node->left = insertToSubtree(node->left, p);
    else if (p > node->getData())
        node->right = insertToSubtree(node->right, p);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->setHeight(1 + std::max(height(node->left),
                                height(node->right)));
 
    int balance = getBalanceFactor(node);
 
    if (balance > 1 && node->left->getData() > p)
        return rightRotate(node);
 
    if (balance < -1 && node->right->getData() > p)
        return leftRotate(node);
 
    if (balance > 1 && node->left->getData() > p)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && node->right->getData() > p)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
int height(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->getHeight();
}