#include <stdio.h>
#include <string.h>

int main()
{
    int n,x;
    
    beg:
    printf("Enter the value to convert :");
    scanf("%f", &x);
    printf("Select the conversion \n1 : inches to miles \n2 : inches to foot \n3 : inches to meters \n4 : pounds to kg \n5 : centimeters to inches \n");
    scanf("%d", &n);
    printf("%f %d", x, n);
    switch (n)
    {
    case 1:
        printf("The distance in miles is %f", (x / 63360));
        break;

    case 2:
        printf("The distance in foot is %f", (x / 12));
        break;

    case 3:
        printf("The distance in meters is %f :", (x * 0.0254));
        break;

    default:
        printf("Enter valid entry. \n\n");
        //goto beg;
        break;
    }
    return 0;
}
/*
inches to miles
inches to foot
cms to inches
pound to kgs
inches to meters
*/
