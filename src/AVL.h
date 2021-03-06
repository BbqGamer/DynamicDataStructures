#ifndef AVL_H
#define AVL_H

#include "BST.h"

class AVL: public BST {
    public:
        AVL(): BST() {};
        ~AVL() {};
        void insert(Person p);
        void remove(int index);

        void setRoot(BSTNode* node);

        std::string getStructureName() {return "AVL";};
};

BSTNode* leftRotate(BSTNode* node);
BSTNode* rightRotate(BSTNode* node);
int getBalanceFactor(BSTNode* node);

BSTNode* insertToSubtree(BSTNode* node, Person p);
BSTNode* deleteFromSubtree(BSTNode* root, int index);
int height(BSTNode* node);

#endif