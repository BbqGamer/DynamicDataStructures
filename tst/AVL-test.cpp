#include "gtest/gtest.h"
#include "AVL.h"

TEST(AVLTest, TestConstructor) {
    AVL tree;
    EXPECT_EQ(tree.getRoot(), nullptr);
}

class AVLtestF : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = Person(1, "Jack", "Brown");
    p2 = Person(2, "Jane", "Doe");
    p3 = Person(3, "John", "Smith");
    p4 = Person(4, "John", "Doe");
    p5 = Person(5, "Jane", "Smith");
    p6 = Person(6, "Jane", "Doe");
    p7 = Person(7, "Jimmy", "Jackson");
    
    tree.insert(p6);tree.getRoot()->setHeight(4);
    tree.insert(p2);tree.getRoot()->getLeft()->setHeight(3);
    tree.insert(p7);tree.getRoot()->getRight()->setHeight(1);
    tree.insert(p1);tree.getRoot()->getLeft()->getLeft()->setHeight(1);
    tree.insert(p4);tree.getRoot()->getLeft()->getRight()->setHeight(2);
    tree.insert(p3);tree.getRoot()->getLeft()->getRight()->getLeft()->setHeight(1);
    tree.insert(p5);tree.getRoot()->getLeft()->getRight()->getRight()->setHeight(1);
  }
    Person p1, p2 ,p3, p4, p5, p6, p7;
    BST tree;
    /*
    RESULTING TREE LOOKS LIKE THIS:
            6
           / \
          2   7
         / \   
        1   4
           / \
          3   5    
    */
};


TEST_F(AVLtestF, TestLeftRotate) {
    BSTNode* y = tree.getRoot()->getLeft();
    tree.getRoot()->setLeft(leftRotate(y));
    EXPECT_EQ(tree.getRoot()->getLeft()->getData(), p4);
    EXPECT_EQ(tree.getRoot()->getLeft()->getRight()->getData(), p5);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft()->getData(), p2);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft()->getLeft()->getData(), p1);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft()->getRight()->getData(), p3);
}

TEST_F(AVLtestF, TestRightRotate) {
    BSTNode* y = tree.getRoot()->getLeft();
    tree.getRoot()->setLeft(leftRotate(y));
    tree.setRoot(rightRotate(tree.getRoot()));
    EXPECT_EQ(tree.getRoot()->getData(), p4);
    EXPECT_EQ(tree.getRoot()->getLeft()->getData(), p2);
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p6);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft()->getData(), p1);
    EXPECT_EQ(tree.getRoot()->getLeft()->getRight()->getData(), p3);
    EXPECT_EQ(tree.getRoot()->getRight()->getLeft()->getData(), p5);
    EXPECT_EQ(tree.getRoot()->getRight()->getRight()->getData(), p7);
}

TEST_F(AVLtestF, TestGetBalanceFactor) {
    EXPECT_EQ(getBalanceFactor(tree.getRoot()), 2);
    EXPECT_EQ(getBalanceFactor(tree.getRoot()->getLeft()), -1);
    EXPECT_EQ(getBalanceFactor(tree.getRoot()->getLeft()->getRight()), 0);
}

TEST(AVLtest, TestInsertToEmpty) {
    AVL tree;
    Person p6 = Person(6, "Jane", "Doe");
    tree.insert(p6);
    EXPECT_EQ(tree.getRoot()->getData(), p6);
}

TEST(AVLtest, TestInserts) {
    AVL tree;
    Person p30, p5, p35, p32, p40, p45;
    p30 = Person(30, "A", "B");
    tree.insert(p30);
    p5 = Person(5, "C", "D");
    tree.insert(p5);
    p35 = Person(35, "E", "F");tree.insert(p35);
    p32 = Person(32, "G", "H");tree.insert(p32);
    p40 = Person(40, "I", "J");tree.insert(p40);
    p45 = Person(45, "K", "L");tree.insert(p45);
    EXPECT_EQ(tree.getRoot()->getData(), p35);
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p40);
    EXPECT_EQ(tree.getRoot()->getRight()->getRight()->getData(), p45);
}