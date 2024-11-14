# include<stdio.h>

int main(){
    int A, B ;
    printf("To perform mathematical operations, specify any 2 numbers\n");
    printf("Please Enter first number");
    scanf("%d", &A);

    printf("Please enter second number");
    scanf("%d", &B);

    printf("Sum of A and B is %d \n", A+B);
    printf("Subtraction of A and B is %d \n", A-B);
    printf("Multiplication of A and B is %d \n", A*B);
    printf("Division of A and B is %d \n", A/B);
    printf("Remainder when A is divided by B is %d \n", A%B);
    printf("Sequence of operation goes from left to right as in 9*10/2 :%d \n", 9*10/2 );
    return 0;
}