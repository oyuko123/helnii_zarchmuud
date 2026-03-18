#include <stdio.h>
#include "interpreter.c"

int main()
{
    char expression[100];

    printf("Arithmetic ilerhiilel oruulna uu: ");
    scanf("%[^\n]", expression);

    int result = interpret(expression);
    printf("Ur dun: %d\n", result);


    return 0;
}
