#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int tokenize(char expression[], char tokens[][20])
{

    int i = 0, j = 0, k = 0;

    while (expression[i] != '\0')
    {

        if (expression[i] == ' ')
        {
            i++;
            continue;
        }

        if (isdigit(expression[i]))
        {
            j = 0;

            while (isdigit(expression[i]))
            {
                tokens[k][j++] = expression[i++];
            }

            tokens[k][j] = '\0';
            k++;
        }

        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/' ||
                 expression[i] == '(' || expression[i] == ')')
        {

            tokens[k][0] = expression[i];
            tokens[k][1] = '\0';

            k++;
            i++;
        }

        else
        {
            i++;
        }
    }

    return k;
}

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int apply(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int interpret(char expression[])
{
    char tokens[MAX][20];
    int count = tokenize(expression, tokens);

    printf("Tokens:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", tokens[i]);
    }

    int values[MAX];
    char ops[MAX];

    int vtop = -1;
    int otop = -1;

    for (int i = 0; i < count; i++)
    {

        if (isdigit(tokens[i][0]))
        {
            values[++vtop] = atoi(tokens[i]);
        }

        else if (tokens[i][0] == '(')
        {
            ops[++otop] = '(';
        }

        else if (tokens[i][0] == ')')
        {
            while (ops[otop] != '(')
            {
                int b = values[vtop--];
                int a = values[vtop--];
                char op = ops[otop--];

                values[++vtop] = apply(a, b, op);
            }
            otop--;
        }

        else
        {
            char op = tokens[i][0];

            while (otop >= 0 && precedence(ops[otop]) >= precedence(op))
            {
                int b = values[vtop--];
                int a = values[vtop--];
                char topop = ops[otop--];

                values[++vtop] = apply(a, b, topop);
            }

            ops[++otop] = op;
        }
    }

    while (otop >= 0)
    {
        int b = values[vtop--];
        int a = values[vtop--];
        char op = ops[otop--];

        values[++vtop] = apply(a, b, op);
    }

    return values[vtop];

}