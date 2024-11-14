#include<stdio.h>
    int add(int x,int y){
        int z = x+y;
        return z;
    }
    int main(){
        int a,b;
        printf("Enter two numbers : \n");
        scanf("%d %d", &a,&b);
        int x = add(a,b);
        printf("The addition of your given number is : %d", x);
        
    }