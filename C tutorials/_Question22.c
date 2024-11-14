#include <stdio.h>
#include <string.h>

int count(char word[]);

int main()
{
    char sample[100];
    printf("Enter characters :");
    fgets(sample, 100, stdin);

    printf("the number of characters in this word is :%d\n", count(sample));

    printf("Or itna sab karne ke bajay, we can use standard function in the string library which will be : ");
    int lngth = strlen(sample);
    printf("%d", lngth); // ek jyada value aa rahi hai
    // it gives usigned integer
    return 0;
}

int count(char word[])
{
    int x = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        x++;
    }
    return x - 1; // this is important because pehle x ++ hoga fir next condition checck hoti hai.
}
