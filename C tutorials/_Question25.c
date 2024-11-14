#include <stdio.h>
#include <string.h>

int vowcounter(char word[]);

int main()
{
    char word[100];
    printf("Enter the word to count its number of vowels :");
    fgets(word, 100, stdin);
    printf("the number of vowels in this word is :%d", vowcounter(word));

    return 0;
}

int vowcounter(char word[])
{
    int x;
    for (int f = 0; word[f] != '\0'; f++)
    {
        if (word[f] == 'a' || word[f] == 'e' || word[f] == 'i' || word[f] == 'o' || word[f] == 'u')
        {
            x++;
        }
        else
        {
            continue;
        }
    }
    return x;
}
// yaha do values kam aa rhae hai