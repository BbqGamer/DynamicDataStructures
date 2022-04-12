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
    node1.setLeft(&node1);
    node2.setRight(&node2);
    EXPECT_EQ(root.getLeft()->getData(), Person(1, "John", "Doe"));
    EXPECT_EQ(root.getLeft()->getLeft(), nullptr);
    EXPECT_EQ(root.getLeft()->getRight(), nullptr);
    EXPECT_EQ(root.getRight()->getData(), Person(2, "Jane", "Doe"));
    EXPECT_EQ(root.getRight()->getLeft(), nullptr);
    EXPECT_EQ(root.getRight()->getRight(), nullptr);
}