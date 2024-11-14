#include <stdio.h>

void indian();
void french();

// When entering anything other than 1 or 2, its being blocked by antivirus
int main()
{
    int n;
    printf("Please enter your nationality Enter 1 for Indian and 2 for French :");
    scanf("%d", &n);

    if (n == 1)
    {
        indian();
    }
    else if (n == 2)
    {
        french();
    }
    else
    {
        printf("Please enter valid nationality");
    }
    switch (n)
    {
    case 1:
        indian();
        break;

    case 2:
        french();
        break;

    default:
        printf("Please enter valid nationality");
    }
    return 0;
}

void indian()
{
    printf("Namaste \n");
}
void french()
{
    printf("Bonjour \n");
}