#include "gtest/gtest.h"
#include "math_operations.h"

TEST(MathOperationsTest, Add_TwoPositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathOperationsTest, Add_NegativeAndPositive) {
    EXPECT_EQ(add(-1, 5), 4);
}

TEST(MathOperationsTest, Add_Zero) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(0, 10), 10);
}

TEST(MathOperationsTest, Add_TwoNegatives) {
    EXPECT_EQ(add(-3, -7), -10);
}
