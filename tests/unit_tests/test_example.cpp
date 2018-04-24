#include "gtest/gtest.h"

int Factorial(int n){
    if ( n == 0 )
        return 1;
    else
        return n*(n-1);
}

TEST(Example, Equals) {
  EXPECT_EQ(1, 1);
}

// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
    EXPECT_EQ(1, Factorial(0));
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
    EXPECT_EQ(1, Factorial(1));
    EXPECT_EQ(2, Factorial(2));
    EXPECT_EQ(6, Factorial(3));
    EXPECT_EQ(40320, Factorial(8));
}