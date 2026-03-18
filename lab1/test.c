#include "unity.h"

int interpret(char expression[]);

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

void test_complex_expression(void)
{
    TEST_ASSERT_EQUAL(14, interpret("2*(4+3)"));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_addition);
    RUN_TEST(test_subtraction);
    RUN_TEST(test_complex_expression);

    return UNITY_END();
}