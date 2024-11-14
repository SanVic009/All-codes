#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float eDistance(int x1, int x2, int y1, int y2)
{
    float distance = hypot((x1 - x2), (y1 - y2));

    return distance;
}

float area(int x1, int x2, int y1, int y2, float (*ptrDistance)(int, int, int, int))
{
    float radius = ptrDistance(x1, x2, y1, y2);
    float area = (3.14) * radius;

    return area;
}

int main()
{
    float (*ptrDistance)(int, int, int, int);
    int x1, x2, y1, y2;

    ptrDistance = eDistance;

    printf("Enter the X coordinates of first point : ");
    scanf("%d", &x1);

    printf("Enter the Y coordinates of first point : ");
    scanf("%d", &y1);

    printf("Enter the X coordinates of second point : ");
    scanf("%d", &x2);

    printf("Enter the Y coordinates of second point : ");
    scanf("%d", &y2);

    printf("The area of the circle with radius %f is %f.\n", ptrDistance(x1, x2, y1, y2), area(x1, x2, y1, y2, ptrDistance));

    return 0;
}