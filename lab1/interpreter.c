#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int tokenize(char exp[], char *tokens[])
{
    int i = 0, k = 0;

    while (exp[i])
    {
        if (exp[i] == "+" || exp[i] == "-"){ 
            k++;
            strcat(tokens[k], exp[i]);
            k++;

        }
        else
        {
            strcat(tokens[k], exp[i]);
        }

        i++;
    }

    return k;
}

int evalTokens(char *tokens[], int *i, int end)
{
    int result = 0;
    int sign = 1;

    while (*i < end)
    {
        if (strcmp(tokens[*i], "+") == 0)
        {
            sign = 1;
        }
        else if (strcmp(tokens[*i], "-") == 0)
        {
            sign = -1;
        }
        else if (strcmp(tokens[*i], "(") == 0)
        {
            (*i)++;
            int value = evalTokens(tokens, i, end);
            result += sign * value;
        }
        else if (strcmp(tokens[*i], ")") == 0)
        {
            return result;
        }
        else
        {
            int value = atoi(tokens[*i]);
            result += sign * value;
        }

        (*i)++;
    }

    return result;
}

int interpret(char exp[])
{
    char *tokens[MAX];          
    int count = tokenize(exp, tokens);

    int i = 0;
    int result = evalTokens(tokens, &i, count);

    return result;
}
