#include "gtest/gtest.h"
#include "AVL.h"

TEST(AVLTest, TestConstructor) {
    AVL tree;
    EXPECT_EQ(tree.getRoot(), nullptr);
}

class AVLtestF : public ::testing::Test {
 protected:
  void SetUp() override {
    p2 = Person(2, "Jane", "Doe");
    p3 = Person(3, "John", "Smith");
    p5 = Person(5, "Jane", "Smith");
    p6 = Person(6, "Jane", "Doe");
    p4 = Person(4, "John", "Doe");
    tree.insert(p3);
    tree.insert(p2);
    tree.insert(p5);
    tree.insert(p4);
    tree.insert(p6);
    tree.getRoot()->setHeight(1);
    tree.getRoot()->getLeft()->setHeight(2);
    tree.getRoot()->getRight()->setHeight(2);
    tree.getRoot()->getRight()->getRight()->setHeight(3);
    tree.getRoot()->getRight()->getLeft()->setHeight(3);
  }
    Person p2 ,p3, p4, p5, p6;
    BST tree;
    /*
    RESULTING TREE LOOKS LIKE THIS:
            3
           / \
          2   5
             / \
             4  6
    */
};

TEST_F(AVLtestF, TestLeftRotate) {
    BSTNode* root = leftRotate(tree.getRoot());
    EXPECT_EQ(root->getData(), p5);
    EXPECT_EQ(root->getRight()->getData(), p6);
    EXPECT_EQ(root->getLeft()->getData(), p3);
    EXPECT_EQ(root->getLeft()->getRight()->getData(), p4);
}