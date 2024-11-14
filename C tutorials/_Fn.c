#include <stdio.h>

// declaration
void printH();

int main()
{
    printH(); // funciton call

    for (int i = 0; i <= 10; i++)
    {
        printH();
    }
    printf("We just printes hello world 100 times");

    return 0;
}

// defining the function here
void printH()
{
    printf("Hello World \n");
}

// isse code chota hota hai aur reusasbility badh jaati hai