#include <stdio.h>

int main()
{
    int price[3];
    printf("enter the price of the first item ");
    scanf("%d", &price[0]);

    printf("enter the price of the second item :");
    scanf("%d", &price[1]);

    printf("enter the price of the third item ");
    scanf("%d", &price[2]);

    for (int i = 0; i <= 2; i++)
    {
        printf("The price of the items no %d with gst is %f \n", i + 1, (price[i] + (price[i] * 0.18)));
    }
    return 0;
}
// without gst, it  is coming alright