#include "gtest/gtest.h"
#include "BST.h"

TEST(BSTtest, TestConstructor) {
    BST tree;
    EXPECT_EQ(tree.getRoot(), nullptr);
}

TEST(BSTNodeTest, TestConstructorEmpty) {
    BSTNode node;
    EXPECT_EQ(node.getLeft(), nullptr);
    EXPECT_EQ(node.getRight(), nullptr);
    EXPECT_EQ(node.getData(), Person());
}

TEST(BSTNodeTest, TestConstructor) {
    Person p = Person(1, "John", "Doe");
    BSTNode node = BSTNode(p);
    EXPECT_EQ(node.getLeft(), nullptr);
    EXPECT_EQ(node.getRight(), nullptr);
    EXPECT_EQ(node.getData(), p);
}


TEST(BSTNodeTest, TestSetAndGetNext) {
    BSTNode root = BSTNode();
    BSTNode node1 = BSTNode(Person(1, "John", "Doe"));
    BSTNode node2 = BSTNode(Person(2, "Jane", "Doe"));
    root.setLeft(&node1);
    root.setRight(&node2);
    EXPECT_EQ(root.getLeft()->getData(), Person(1, "John", "Doe"));
    EXPECT_EQ(root.getLeft()->getLeft(), nullptr);
    EXPECT_EQ(root.getLeft()->getRight(), nullptr);
    EXPECT_EQ(root.getRight()->getData(), Person(2, "Jane", "Doe"));
    EXPECT_EQ(root.getRight()->getLeft(), nullptr);
    EXPECT_EQ(root.getRight()->getRight(), nullptr);
}

TEST(BSTtest, TestInsertToEmptyTree) {
    BST tree;
    Person p = Person(1, "John", "Doe");
    tree.insert(p);
    EXPECT_EQ(tree.getRoot()->getData(), p);
}

class BSTtestF : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = Person(1, "John", "Doe");
    p2 = Person(2, "Jane", "Doe");
    p3 = Person(3, "John", "Smith");
    p4 = Person(4, "Jane", "Smith");
    tree.insert(p3);
    tree.insert(p2);
    tree.insert(p1);
    tree.insert(p4);
  }
    Person p1;
    Person p2;
    Person p3;
    Person p4;
    BST tree;
};

TEST_F(BSTtestF, InsertToTree) {
    EXPECT_EQ(tree.getRoot()->getData(), p3);
    EXPECT_EQ(tree.getRoot()->getLeft()->getData(), p2);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft()->getData(), p1);
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p4);
}