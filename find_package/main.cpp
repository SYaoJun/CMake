#include "gtest/gtest.h"

int add(int a, int b) {
    return a + b;
}

TEST(AddFunctionTest, PositiveNumbers) {
    int *a = new int(2);
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-1, 1), 0);
}