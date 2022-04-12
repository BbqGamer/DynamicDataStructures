#include "Person.h"

class BSTNode {
    BSTNode *left;
    BSTNode *right;
    Person data;
public:
    BSTNode(): left(nullptr), right(nullptr), data(Person()) {};
    BSTNode(Person p): left(nullptr), right(nullptr), data(p) {};
    
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