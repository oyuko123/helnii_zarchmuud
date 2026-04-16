#include <stdio.h>
#include "interpreter.c"

int main()
{
    char exp[100];

    printf("Ilerhiilel oruulna uu: ");
    fgets(exp, sizeof(exp), stdin);

    int result = interpret(exp);
    printf("Ur dun = %d\n", result);

    return 0;
}
