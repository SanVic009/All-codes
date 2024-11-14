#include <stdio.h>
#include <string.h>

//done in cpp
void parse(char *input)
{
    int flip, index = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '<')
        {
            flip = 1;
            continue;
        }
        else if (input[i] == '>')
        {
            flip = 0;
            continue;
        }
        if (flip == 0)
        {
            input[index] = input[i];
        }
        input[index] = '\0';
    }
}

int main()
{
    char input[] = "<h1> This is a heading </h1>";
    parse(input);
    printf("the final string is ~%s~", input);
    return 0;
}