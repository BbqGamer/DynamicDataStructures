#include "gtest/gtest.h"
#include "AVL.h"

TEST(AVLTest, TestConstructor) {
    AVL tree;
    EXPECT_EQ(tree.getRoot(), nullptr);
}

TEST(AVLNodeTest, TestConstructorEmpty) {
    AVLNode node;
    EXPECT_EQ(node.getLeft(), nullptr);
    EXPECT_EQ(node.getRight(), nullptr);
    EXPECT_EQ(node.getData(), Person());
    EXPECT_EQ(node.getHeight(), 0);
}

TEST(AVLNodeTEst, TestConstructor) {
    Person p = Person(1, "John", "Doe");
    AVLNode node = AVLNode(p);
    EXPECT_EQ(node.getLeft(), nullptr);
    EXPECT_EQ(node.getRight(), nullptr);
    EXPECT_EQ(node.getData(), p);
    EXPECT_EQ(node.getHeight(), 0);
}