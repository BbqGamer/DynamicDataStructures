#ifndef AVL_H
#define AVL_H

#include "BST.h"

class AVL: public BST {
    public:
        AVL() {};
        ~AVL() {};
        void insert(Person p);
};

class AVLNode: public BSTNode {
    int height;

    public:
        AVLNode(): BSTNode(), height(0) {};
        AVLNode(Person p): BSTNode(p), height(0) {};

        int getHeight();
};

#endif