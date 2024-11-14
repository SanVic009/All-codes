#include <stdio.h>

int add(int x, int y)
{
    int z = x + y;
    return z;
}

int sub(int x, int y)
{
    int z = x - y;
    return z;
}

int mult(int x, int y)
{
    int z = x * y;
    return z;
}

int div(int x, int y)
{
    float z = x / y;
    return z;
}

int main()
{
    int a, b, c, x;
    printf("Enter two numbers : \n");
    scanf("%d %d", &a, &b);

    do
    {
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division");
        printf("\n Choose one of the option.\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            int p = add(a, b);
            printf("Addition of two number is : %d\n", p);
            break;
        case 2:
            int q = sub(a, b);
            printf("Subtraction of two number is : %d\n", q);
            break;
        case 3:
            int r = mult(a, b);
            printf("Multiplication of two number is : %d\n", r);
            break;
        case 4:
            int s = div(a, b);
            printf("Division of two number is : %f\n", s);
            break;
        default:
            printf("You have choose wrong number");
            break;
        }
        printf("Enter 1 for continue");
        scanf("%d", &x);
    } while (x == 1);
    return 0;
}