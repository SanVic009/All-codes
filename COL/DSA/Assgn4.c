/*
Sanchit Sovale
31
1032230669
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char opStack[25];  
int opTop = -1;  

void infixToPostfix(char infix[25]);
void postfixToInfix(char postfix[25]);

void pushOp(char c);
char popOp();
int precedenceInStack(char c);
int precedenceIncoming(char c);

int main() {
    int choice;
    char expression[25];

    do { 
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Postfix to Infix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", expression);
                infixToPostfix(expression);
                break;
            
            case 2:
                printf("Enter the postfix expression: ");
                scanf("%s", expression);
                postfixToInfix(expression);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}

void pushOp(char c) {
    opTop++;
    opStack[opTop] = c;
}

char popOp() {
    char t = opStack[opTop];
    opTop--;
    return t;
}

int precedenceInStack(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    if (c == '(') return 0;
    return -1;
}

int precedenceIncoming(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 4;
    if (c == '(') return 5;
    return -1;
}

void infixToPostfix(char infix[25]) {
    char postfixExp[25];
    int k = 0, i = 0;
    char currentToken = infix[i];

    while (currentToken != '\0') {
        if (isalnum(currentToken)) {
            postfixExp[k] = infix[i];
            k++;
        } else {
            if (currentToken == '(') {
                pushOp('(');
            } else if (currentToken == ')') {
                while ((currentToken = popOp()) != '(') {
                    postfixExp[k] = currentToken;
                    k++;
                }
            } else {
                while (opTop != -1 && precedenceInStack(opStack[opTop]) >= precedenceIncoming(currentToken)) {
                    postfixExp[k] = popOp();
                    k++;
                }
                pushOp(currentToken);
            }
        }
        i++;
        currentToken = infix[i];
    }

    while (opTop != -1) {
        postfixExp[k] = popOp();
        k++;
    }

    postfixExp[k] = '\0';
    printf("\nPostfix expression = %s\n", postfixExp);
}

void postfixToInfix(char postfix[25]) {
    char infixExp[50][25];  
    int top = -1;
    char currentToken;
    int i = 0;

    while ((currentToken = postfix[i]) != '\0') {
        if (isalnum(currentToken)) {
            top++;
            char operand[2] = {currentToken, '\0'};
            strcpy(infixExp[top], operand);
        } else {
            char operand2[25], operand1[25];
            strcpy(operand2, infixExp[top--]);  
            strcpy(operand1, infixExp[top--]);  

            char newExpr[50] = "";
            strcat(newExpr, operand1);
            strncat(newExpr, &currentToken, 1);
            strcat(newExpr, operand2);

            top++;
            strcpy(infixExp[top], newExpr);
        }
        i++;
    }

    printf("\nInfix expression = %s\n", infixExp[top]);
}

/*
#####################  OUTPUT  #####################

Menu:
1. Infix to Postfix
2. Postfix to Infix
3. Exit
Enter your choice: 1
Enter the infix expression: A*B+(C+D)-E

Postfix expression = AB*CD++E-

Menu:
1. Infix to Postfix
2. Postfix to Infix
3. Exit
Enter your choice: 2
Enter the postfix expression: AB*CD++E-

Infix expression = A*B+C+D-E

Menu:
1. Infix to Postfix
2. Postfix to Infix
3. Exit
Enter your choice: 3
Exiting...
PS C:\Users\Sanch\OneDrive\Sanchit\All codes\COL\DSA>

*/