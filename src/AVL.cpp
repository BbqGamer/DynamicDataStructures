#include "AVL.h"

BSTNode *leftRotate(BSTNode *x)
{
    BSTNode *y = x->getRight();
    BSTNode *T2 = y->getLeft();
 
    y->setLeft(x);
    x->setRight(T2);
 
    x->setHeight(std::max(height(x->getLeft()),   
                    height(x->getRight())) + 1);

    y->setHeight(std::max(height(y->getLeft()),
                    height(y->getRight())) + 1);
 
    return y;
}

BSTNode *rightRotate(BSTNode *y)
{
    BSTNode *x = y->getLeft();
    BSTNode *T2 = x->getRight();
 
    x->setRight(y);
    y->setLeft(T2);
 
    y->setHeight(std::max(height(y->getLeft()),   
                    height(y->getRight())) + 1);

    x->setHeight(std::max(height(x->getLeft()),
                    height(x->getRight())) + 1);
 
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
    std::cout << node->getData() << p << balance << std::endl;

    if (balance > 1 && node->left->getData() > p) {
        std::cout << "HERE 1" << std::endl;
        return rightRotate(node);
    }
 
    if (balance < -1 && p > node->right->getData()) {
        std::cout << "HERE: 2" << std::endl;
        return leftRotate(node);
    }
 
    if (balance > 1 && p > node->left->getData())
    {
        std::cout << "HERE: 3" << std::endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && node->right->getData() > p)
    {
        std::cout << "HERE: 4" << std::endl;
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