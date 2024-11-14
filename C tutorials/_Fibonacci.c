#include <stdio.h>
// this is not complete
int fib(int n);

int main()
{
    int n;
    printf("Enter the number of terms required in the fibonacci sequence :");
    scanf("%d", &n);

    fib(n);
    return 0;
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        if (n == 0)
        {

            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
    }

    int fibN1 = fib(n - 1);
    int fibN2 = fib(n - 2);
    int fibN = fibN1 + fibN2;

    printf("%d \n", fibN);
    // cant we write it like (int fibN=fib(n-1)+fib(n-2))
}

// if (n==1){
//     return 0;
// }
// if (n==2)
// {
//     return 1;
// }