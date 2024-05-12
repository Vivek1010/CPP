// Following is the unit test case file
// 1 - fizzBuzzFunction must be callable
// 2 - should return "Fizz" if passed 1.
// 3 - should return "Buzz" if passed 2.
// 4 - should return "Fizz" if passed 3.

#include <iostream>
#include <gtest/gtest.h>

bool isMultiple(int value, int base)
{
    if (value % base == 0)
    {
        return true;
    }
    return false;
}
std::string
fizzBuzzFunction(int value)
{
    if (isMultiple(value, 3))
    {
        return ("Fizz");
    }

    if (value == 1)
    {
        return "Fizz";
    }

    if (value == 2)
    {
        return "Buzz";
    }
    return "";
}

TEST(FizzBuzzTestSuit, pass_1)
{
    ASSERT_EQ("Fizz", fizzBuzzFunction(1));
}

TEST(FizzBuzzTestSuit, pass_2)
{
    ASSERT_EQ("Buzz", fizzBuzzFunction(2));
}

TEST(FizzBuzzTestSuit, pass_3)
{
    ASSERT_EQ("Fizz", fizzBuzzFunction(3));
}

TEST(FizzBuzzTestSuit, pass_6)
{
    ASSERT_EQ("Fizz", fizzBuzzFunction(6));
}
