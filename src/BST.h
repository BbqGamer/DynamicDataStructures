#include "Person.h"

class BSTNode {
    BSTNode *left;
    BSTNode *right;
    Person data;
public:
    BSTNode(): left(nullptr), right(nullptr), data(Person()) {};
    BSTNode* getRight();
    BSTNode* getLeft();
    Person getData();

};

class BST {
    BSTNode* root;

    public:
    BST(): root(nullptr) {};

    BSTNode* getRoot();
};