#include "Person.h"

class BSTNode {
public:
    BSTNode *left;
    BSTNode *right;
    Person data;
};

class BST {
    BSTNode* root;

    public:
    BST(): root(nullptr) {};

    BSTNode* getRoot();
};