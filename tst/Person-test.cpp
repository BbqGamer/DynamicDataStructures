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
