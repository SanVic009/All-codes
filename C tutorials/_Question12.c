#include <stdio.h>

float marks(int s, int m, int k);

int main()
{
    int s, m, k;
    printf("Please enter the marks of Sciemce :");
    scanf("%d", &s);

    printf("Please enter the marks of maths :");
    scanf("%d", &m);

    printf("Please enter the marks of Sanskrit :");
    scanf("%d", &k);

    printf("Average marks of the student are : %f ", marks(s, m, k));
    return 0;
}

float marks(int s, int m, int k)
{
    float avg = ((s + m + k) / 300) * 100;
    return avg;
}
// for some reason, answer hamesha 0 hi aa raha hai
// aur jabb mai 9.0 daal raha hu toh baki entry le hi nahi raha hai.