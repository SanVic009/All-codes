#include <stdio.h>

int main()
{
    char ch;
    printf("Please enter your character to check if it is capital or not: ");
    scanf("%c", &ch);

    if ((ch >= 'A') && (ch <= 'Z'))
    {
        printf("The character enterd is Capital letter");
    }
    else if ((ch >= 'a') && (ch <= 'z'))
    {
        printf("The character enterd is small letter ");
    }
    else
    {
        printf("Please enter an alphabet");
    }
    return 0;
}
// I want it to ask for input again if condition goes to else
//  future me, maybe we will have to use functions.