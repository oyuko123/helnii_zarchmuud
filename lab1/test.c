#include "unity.h"

int interpret(char exp[]);

void setUp(void) {}
void tearDown(void) {}

void test_addition(void)
{
    TEST_ASSERT_EQUAL(8, interpret("3+5"));
}

void test_subtraction(void)
{
    TEST_ASSERT_EQUAL(5, interpret("7-2"));
}

void test_parentheses(void)
{
    TEST_ASSERT_EQUAL(3, interpret("5-(8-4)+2"));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_addition);
    RUN_TEST(test_subtraction);
    RUN_TEST(test_parentheses);

    return UNITY_END();
}