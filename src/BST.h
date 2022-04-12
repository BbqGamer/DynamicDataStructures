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

    void setLeft(BSTNode* node);
    void setRight(BSTNode* node);
};

class BST {
    BSTNode* root;

    public:
    BST(): root(nullptr) {};
    ~BST();

    BSTNode* getRoot();
    void insert(Person p);
    Person search(int index);
};

void deleteSubtree(BSTNode* node);