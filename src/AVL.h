#ifndef AVL_H
#define AVL_H

#include "BST.h"

class AVL: public BST {
    public:
        AVL() {};
        ~AVL() {};
        //void insert(Person p);
};

BSTNode* leftRotate(BSTNode* node);
BSTNode* rightRotate(BSTNode* node);

#endif