#include "gtest/gtest.h"
#include "Person.h"

TEST(PersonTest, TestConstructors) {
    Person p;
    EXPECT_EQ(p.getIndex(), 0);
    EXPECT_EQ(p.getFirstname(), "");
    EXPECT_EQ(p.getLastname(), "");

    Person p1(1, "John", "Doe");
    EXPECT_EQ(p1.getIndex(), 1);
    EXPECT_EQ(p1.getFirstname(), "John");
    EXPECT_EQ(p1.getLastname(), "Doe");
}

TEST(PersonTest, TestComparision) {
    Person p1(1, "John", "Doe");
    Person p2(1, "John", "Doe");
    Person p3(2, "John", "Doe");
    Person p4(1, "Jane", "Doe");
    Person p5(1, "John", "Smith");

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    EXPECT_FALSE(p1 == p4);
    EXPECT_FALSE(p1 == p5);
}

