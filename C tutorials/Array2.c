#include <stdio.h>

int main()
{
    int marks[3];
    printf("This is to reprint the marks of tests using arrays\v");
    printf("Enter the marks of physics test :");
    scanf("%d", &marks[0]);

    printf("Enter the marks of Maths test :");
    scanf("%d", &marks[1]);

    printf("Enter the marks of english test :");
    scanf("%d", &marks[2]);

    printf("The marks in the physics test are :%d\n", marks[0]);
    printf("the marks in maths test are :%d \n", marks[1]);
    printf("The marks in the english test are:%d\n", marks[2]);
    return 0;
}