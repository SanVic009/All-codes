# include<stdio.h>

void ops(int a,int b,int *sum, int *prod, float *avg); 

int main(){
    int a,b,sum,prod;
    float avg;
    printf("please enter 2 numbers to find their sum product and average\n");
    printf("Enter first number");
    scanf("%d", &a);

    printf("Enter the second number");
    scanf("%d", &b);

    ops(a,b,&sum,&prod,&avg);

    printf("The sum of a and b is %d\n", sum);
    printf("The product of a and b is %d\n", prod);
    printf("The average of a and b is %f\n", avg);
    return 0;
}

void ops(int a,int b,int *sum, int *prod, float *avg){
    *sum=a+b;
    *prod=a*b;
    *avg=(a+b)/2;
}