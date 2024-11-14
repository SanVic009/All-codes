#include <stdio.h>
int main()
{
    int a, b, add, sub, mult, div;

    printf("Enter two numbers : \n");
    scanf("%d %d", &a, &b);

    printf("Addition of two number is : %d\n", a + b);
    printf("Subtraction of two number is : %d\n", a - b);
    printf("Multiplication of two number is : %d\n", a * b);
    printf("Division of two number is : %f\n", a / b);
    return 0;
}