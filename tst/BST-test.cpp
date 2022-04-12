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