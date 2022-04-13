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
    p5 = Person(5, "Jane", "Smith");
    p6 = Person(6, "Jane", "Doe");
    p4 = Person(4, "John", "Doe");
    tree.insert(p3);
    tree.insert(p2);
    tree.insert(p1);
    tree.insert(p5);
    tree.insert(p4);
    tree.insert(p6);
  }
    Person p1;
    Person p2;
    Person p3;
    Person p5;
    Person p4;
    Person p6;
    BST tree;
};

TEST_F(BSTtestF, InsertToTree) {
    EXPECT_EQ(tree.getRoot()->getData(), p3);
    EXPECT_EQ(tree.getRoot()->getLeft()->getData(), p2);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft()->getData(), p1);
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p5);
}

TEST_F(BSTtestF, SearchTree) {
    EXPECT_EQ(tree.search(1), p1);
    EXPECT_EQ(tree.search(2), p2);
    EXPECT_EQ(tree.search(3), p3);
    EXPECT_EQ(tree.search(5), p5);
}

TEST_F(BSTtestF, SearchTreeException) {
    ASSERT_THROW(tree.search(8), std::out_of_range);
    ASSERT_THROW(tree.search(-1), std::out_of_range);
    ASSERT_THROW(tree.search(10000000), std::out_of_range);
}

TEST_F(BSTtestF, RemoveFromTreeException) {
    ASSERT_THROW(tree.remove(8), std::out_of_range);
    ASSERT_THROW(tree.remove(-3553), std::out_of_range);
    ASSERT_THROW(tree.remove(1252352), std::out_of_range);
}

TEST_F(BSTtestF, RemoveWithNoChildren) {
    tree.remove(1);
    EXPECT_EQ(tree.getRoot()->getData(), p3);
    EXPECT_EQ(tree.getRoot()->getLeft()->getData(), p2);
    EXPECT_EQ(tree.getRoot()->getLeft()->getLeft(), nullptr);
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p5);
    tree.remove(2);
    tree.remove(4);
    tree.remove(6);
    tree.remove(5);
    EXPECT_EQ(tree.getRoot()->getData(), p3);
    EXPECT_EQ(tree.getRoot()->getLeft(), nullptr);
    EXPECT_EQ(tree.getRoot()->getRight(), nullptr);
}

TEST_F(BSTtestF, RemoveWithOneChild) {
    tree.remove(1);
    tree.remove(4);
    tree.remove(5); //THIS
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p6);
    tree.remove(6);
    tree.remove(3); //THIS
    tree.remove(2);
    EXPECT_EQ(tree.getRoot(), nullptr);
}

TEST_F(BSTtestF, FindMin) {
    EXPECT_EQ(tree.getRoot()->findMin()->getData(), p1);
    EXPECT_EQ(tree.getRoot()->getRight()->findMin()->getData(), p4);
}

TEST_F(BSTtestF, RemoveWithTwoChildren) {
    tree.remove(5); //THIS
    EXPECT_EQ(tree.getRoot()->getRight()->getData(), p6);
    EXPECT_EQ(tree.getRoot()->getRight()->getLeft()->getData(), p4);
    tree.remove(4);
    tree.remove(1);
    tree.remove(3); //THIS
    EXPECT_EQ(tree.getRoot()->getData(), p6);
    EXPECT_EQ(tree.getRoot()->getLeft()->getData(), p2);
}

