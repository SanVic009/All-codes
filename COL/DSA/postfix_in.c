#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

char stack[MAX][MAX];
int top = -1;

char *op1, *op2;


int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push(char *str)
{
    if (!isFull())
    {
        strcpy(stack[++top], str);
    }
    else
    {
        printf("Stack Full!!!!\n");
    }
}

char* pop() {
    static char result[MAX];

    if (!isEmpty()) {
        strcpy(result, stack[top--]);
        return result;
    } else {
        result[0] = '\0';
        return result;
    }
}

void post_in(char exp[MAX])
{
    char str1[MAX], str[MAX], op1[MAX], op2[MAX], str2[MAX];
    int i, j;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isalpha(exp[i]))
        {
            char operand[2] = {exp[i], '\0'}; 
            push(operand);
        }
        else
        {
            pop(op1);
            pop(op2);

            str2[0] = '(';
            str2[1] = '\0';

            strcat(str2, op2);
            int len = strlen(str2);
            str2[len] = exp[i];
            str2[len + 1] = '\0';

            strcat(str2, op1);

            len = strlen(str2);
            str2[len] = ')';
            str2[len + 1] = '\0';

            push(str2);
        }
    }
    strcpy(str1, pop());
    printf("Infix expression is :%s\n", str1);
}

int main()
{
    char postexp[] = "ab+c*de/f-";
    post_in(postexp);
    return 0;
}