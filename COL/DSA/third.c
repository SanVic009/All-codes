#include<stdio.h>
int main(){
    int a,b,c,x;
    printf("Enter two numbers : \n");
     scanf("%d %d", &a,&b);

    do
    {
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division");
    printf("\n Choose one of the option.\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("Addition of two number is : %d\n", a+b);
        break;
    case 2:
        printf("Subtraction of two number is : %d\n", a-b);
        break;
    case 3:
        printf("Multiplication of two number is : %d\n", a*b);
        break;
    case 4:
        printf("Division of two number is : %f\n", a/b);
        break;
    default:
        printf("You have choose wrong number");
        break;
    }
    printf("Enter 1 for continue");
    scanf("%d",&x);
    }while(x==1);
    return 0;
}