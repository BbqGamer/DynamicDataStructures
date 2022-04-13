#include "Person.h"

class BSTNode {
public:
    BSTNode *left;
    BSTNode *right;
    Person data;
    int height;

    BSTNode(): left(nullptr), right(nullptr), data(Person()), height(1) {};
    BSTNode(Person p): left(nullptr), right(nullptr), data(p), height(1) {};
    BSTNode(BSTNode* node): left(node->left), right(node->right), data(node->data), height(1) {};

    BSTNode* getRight();
    BSTNode* getLeft();
    Person getData();
    void setData(Person p);

    int getHeight();
    void setHeight(int _height);

    BSTNode* findMin();
    void remove(int index);

    void setLeft(BSTNode* node);
    void setRight(BSTNode* node);
    
};

class BST {
    BSTNode* root;

    public:
    BST(): root(nullptr) {};
    ~BST();

    void setRoot(BSTNode* node);
    BSTNode* getRoot();

    void insert(Person p);
    Person search(int index);
    void remove(int index);

};

void deleteSubtree(BSTNode* node);
BSTNode* removeFromSubtree(BSTNode* root, int index);

void printINORDER(BSTNode* root);
void printPREORDER(BSTNode* root);
void printPOSTORDER(BSTNode* root);