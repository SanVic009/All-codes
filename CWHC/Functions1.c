#include <stdio.h>
#include <string.h>
void changeval(int a, int b);
void changeref(int*a, int*b);

int main(){
    int a, b;
    printf("Enter valuse of a and b to swap their values\n.");
    printf("Enter the value of a :");
    scanf("%d", &a);

    printf("Enter the value of b :");
    scanf("%d", &b);

    printf("THe values of a and b are %d and %d resp.\n", a, b);

    printf("Now after swapping the values useing the call by value function is \n:");

    changeval(a, b);

    printf("The values of a and b after swapping their values using call by reference is :\n");

    changeref(&a, &b);
    return 0;
}
void changeval(int a, int b){
    int x=a;
    a=b;
    b=x;
    printf("%d and %d resp\n",a,b);
}

void changeref(int*a, int*b){
    int x=*a;
    *a=*b;
    *b=x;
    printf("%d and %d resp\n",a,b);
}