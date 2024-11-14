#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int a, int b){
    return a+b;
}

int main(){
    
    printf("The sum of 3 and 9 by direct calling is :%d\n", add(3,9));

    int (*ptrFunction)(int, int);
    ptrFunction=&add;
    //dont forget to assing the value to the function pointer. line 14

    printf("The sum of 3 and 8 by calling the function with a pointer is :%d\n", (*ptrFunction)(3,8));

    return 0;
}