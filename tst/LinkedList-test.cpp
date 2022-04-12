#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(LinkedListTest, TestConstructor) {
    LinkedList list;
    EXPECT_EQ(list.head, nullptr);
}

TEST(LinkedListNodeTest, TestConstructorEmpty) {
    LinkedListNode node;
    EXPECT_EQ(node.getNext(), nullptr);
    EXPECT_EQ(node.getData(), Person());
}

TEST(LinkedListNodeTest, TestConstructor) {
    Person p = Person(1, "John", "Doe");
    LinkedListNode node1 = LinkedListNode(p);
    EXPECT_EQ(node1.getNext(), nullptr);
    EXPECT_EQ(node1.getData(), p);
}

TEST(LinkedListNodeTest, TestSetAndGetNext) {
    LinkedListNode node1 = LinkedListNode();
    LinkedListNode node2 = LinkedListNode(Person(1, "John", "Doe"));
    node1.setNext(&node2);
    EXPECT_EQ(node1.getNext(), &node2);
    EXPECT_EQ(node1.getNext()->getNext(), nullptr);
    EXPECT_EQ(node1.getNext()->getData(), Person(1, "John", "Doe"));
}

TEST(LinkedListTest, TestInsertToEmptyList) {
    LinkedList list;
    Person p = Person(1, "John", "Doe");
    list.insertNode(p);
    EXPECT_EQ(list.head->getData(), p);
}

class LinkedListTestF : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = Person(1, "John", "Doe");
    p2 = Person(2, "Jane", "Doe");
    p3 = Person(3, "John", "Smith");
    list.insertNode(p3);
    list.insertNode(p1);
    list.insertNode(p2);
  }
    Person p1;
    Person p2;
    Person p3;
    LinkedList list;
};

TEST_F(LinkedListTestF, InsertToList) {
    EXPECT_EQ(list.head->getData(), p1);
    EXPECT_EQ(list.head->getNext()->getData(), p2);
    EXPECT_EQ(list.head->getNext()->getNext()->getData(), p3);
}

TEST_F(LinkedListTestF, SearchList) {
    EXPECT_EQ(list.search(1), p1);
    EXPECT_EQ(list.search(2), p2);
    EXPECT_EQ(list.search(3), p3);
}

TEST_F(LinkedListTestF, RemoveFromListException) {
    ASSERT_THROW(list.removeNode(4), std::out_of_range);
    ASSERT_THROW(list.removeNode(-1), std::out_of_range);
    ASSERT_THROW(list.removeNode(100), std::out_of_range);
}

TEST_F(LinkedListTestF, RemoveFromList) {
    list.removeNode(1);
    EXPECT_EQ(list.head->getData(), p2);
    EXPECT_EQ(list.head->getNext()->getData(), p3);
    EXPECT_EQ(list.head->getNext()->getNext(), nullptr);
    list.removeNode(3);
    EXPECT_EQ(list.head->getData(), p2);
    EXPECT_EQ(list.head->getNext(), nullptr);
}
