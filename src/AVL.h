#ifndef AVL_H
#define AVL_H

#include "BST.h"

class AVL: public BST {
    public:
        AVL() {};
        ~AVL() {};
        void insert(Person p);

        void setRoot(BSTNode* node);
};

BSTNode* leftRotate(BSTNode* node);
BSTNode* rightRotate(BSTNode* node);
int getBalanceFactor(BSTNode* node);

BSTNode* insertToSubtree(BSTNode* node, Person p);
int height(BSTNode* node);

#endif