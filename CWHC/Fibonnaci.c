#include <stdio.h>
#include <string.h>

int fibonacci(int n);

int main()
{
    int n;
    printf("Enter the number of desired elements in the fibonacci sequence :");
    scanf("%d", &n);

    printf("%d", fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }else if (n == 2)
    {
        return 1;
    }else{
    return fibonacci(n-1) + fibonacci(n - 2);}
}