# include<stdio.h>

int sum(int a, int b);

int main(){
    int a,b,s;
    printf("ENter numbers a and b to find their sum using a function \n");
    printf("Please enter number a: ");
    scanf("%d", &a);

    printf("Please enter number b: ");
    scanf("%d", &b);

    s=sum(a,b);
    printf("the sum will be :%d \n", s);

    return 0;
}
int sum(int a, int b){
    return a+b;
}