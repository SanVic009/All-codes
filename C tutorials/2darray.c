#include <stdio.h>

// usage of 2d arrays

int main()
{
    int marks[2][3];

    marks[0][0] = 1;
    marks[0][1] = 2;
    marks[0][2] = 3;
    marks[1][0] = 4;
    marks[1][1] = 5;
    marks[1][2] = 6;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("the marks are %d\n", marks[i][j]);
        }
    }
    return 0;
}