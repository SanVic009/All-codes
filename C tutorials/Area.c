#include <stdio.h>
#include <math.h>

// math .h is for the power function//

int main()
{
    int side;
    int x = 2;

    printf("Enter the side of square to find its area:");
    scanf("%d", &side);

    printf("The area of the square is %d \n", side * side);
    printf("The area of the square is %f", pow(side, 2));
    return 0;
}
// pow function is giving zero
// kyuki maine pow ke liye int use kiya tha jabki uska data type double which is bigger than int so uske liye float use kiya