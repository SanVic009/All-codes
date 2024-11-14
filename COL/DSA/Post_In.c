#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20

char stack[MAX];
int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX-1;
}

char pop(char *result) {
    if (isEmpty())
        return -1;

    char ch = stack[top];
    top--;
    return ch;
}

void push(char *oper) {
    if (isFull())
        printf("Stack Full!!!!\n");
    else {
        top++;
        stack[top] = oper;
    }
}

int post_in(char postexp[], char outexp[]){
    int i , j;
    for (i = 0, j = 0; postexp[i]; i++)
    {
        if(isalpha(postexp[i]))
        {
            push(postexp[i]);
        }
        else
        {
            if (!isEmpty())
                return -1;
            else
            {
                outexp[j++] = pop(stack[top]);
                outexp[j++] = postexp[i];
                outexp[j++] = pop(stack[top]);
            }
        }
    }

    outexp[j] = '\0';
    printf("%s\n", outexp);
    return 0;
    
}

int main(){
    char postexp[] = "PQR^*S+";
    char outexp[MAX] = {0};

    int success = post_in(postexp, outexp);
    if(success == -1)
        printf("Try again!\n");
    
    return 0;
}