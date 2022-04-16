#include "AVL.h"
#include "BST.h"

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

    if (balance > 1 && node->left->getData() > p) {
        return rightRotate(node);
    }
 
    if (balance < -1 && p > node->right->getData()) {
        return leftRotate(node);
    }
 
    if (balance > 1 && p > node->left->getData())
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && node->right->getData() > p)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

void AVL::remove(int index) {
    BSTNode* ptr = removeFromSubtree(this->getRoot(), index);
    setRoot(ptr);
}

BSTNode* deleteFromSubtree(BSTNode* root, int index) {
     
    if (root == nullptr)
        return root;
 
    if ( index < root->getData().getIndex() )
        root->left = deleteFromSubtree(root->left, index);

    else if( index > root->getData().getIndex() )
        root->right = deleteFromSubtree(root->right, index);
 
    else
    {
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            BSTNode* temp = root->left ?
                         root->left :
                         root->right;
 
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else 
            *root = *temp; 
            free(temp);
        }
        else
        {
            BSTNode* temp = root->right->findMin();
 
            root->setData(temp->getData());
 
            root->right = deleteFromSubtree(root->right,
                                            temp->getData().getIndex());
        }
    }
 
    if (root == nullptr)
    return root;
 
    root->height = 1 + std::max(height(root->left),
                                height(root->right));
 
    int balance = getBalanceFactor(root);
 
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);
 
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);
 
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}


int height(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->getHeight();
}