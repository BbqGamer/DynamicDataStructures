#include "gtest/gtest.h"
#include "Person.h"

TEST(PersonTest, TestConstructor) {
    Person p;
    EXPECT_EQ(p.getIndex(), 0);
    EXPECT_EQ(p.getFirstname(), "");
    EXPECT_EQ(p.getLastname(), "");
}
