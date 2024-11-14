#include <stdio.h>
#include <string.h>

void pat1(int n);
void pat2(int n);
void pat3(int n);

int main()
{
    int a, n;
    printf("Enter the numher for the desired pattern :");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        printf("enter the numbers of the stars in a triangular pattern :");
        scanf(" %d", &n);
        pat1(n);
        break;
    case 2:
        printf("enter the numbers of the stars in the upside down triangle pattern :");
        scanf(" %d", &n);
        pat2(n);
        break;
    case 3:
        printf("enter the numbers of the stars in a 90 degree rotated pattern :");
        scanf(" %d", &n);
        pat3(n);
        break;
    default:
        printf("Enter valid pattern number");
    }
    return 0;
}

void pat1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*\t");
        }
        printf("\n");
    }
}

void pat2(int n)
{
    for (int i = 0; i > n; i++)
    {
        for (int j = 0; j <= n-i-1; j++)
        {
            printf("* \t");
        }
        printf("\n");
    }
}

void pat3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*\t");
        }
        printf("\n");
    }
    for (int i = 0; i > n; i++)
    {
        for (int j = 0; j <= n-i-1; j++)
        {
            printf("* \t");
        }
        printf("\n");
    }
}
