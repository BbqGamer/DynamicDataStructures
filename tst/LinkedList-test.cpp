#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(LinkedListTest, TestConstructor) {
    LinkedList list;
    EXPECT_EQ(list.head, nullptr);
}

TEST(LinkedListNodeTest, TestConstructor) {
    LinkedListNode node;
    EXPECT_EQ(node.getNext(), nullptr);
    EXPECT_EQ(node.getData(), Person());

    Person p = Person(1, "John", "Doe");
    LinkedListNode node1 = LinkedListNode(p);
    EXPECT_EQ(node1.getNext(), nullptr);
    EXPECT_EQ(node1.getData(), p);
}

// TEST(LinkedListTest, TestInsertNode) {
//     LinkedList list;
//     Person p = Person(1, "John", "Doe");
//     list.insertNode(p);
//     EXPECT_EQ(list.head->getData(), p);
// }
