# include<stdio.h>

int main(){
    int A, B ;
    printf("To perform mathematical operations, specify any 2 numbers\n");
    printf("Please Enter first number");
    scanf("%d", &A);

    printf("Please enter second number");
    scanf("%d", &B);

    int sum = A +B;
    int multiplication = A*B;
    int subtraction = A-B;
    int division = A/B;

    printf("Sum of A and B is %d \n", sum);
    printf("Subtraction of A and B is %d \n", subtraction);
    printf("Multiplication of A and B is %d \n", multiplication);
    printf("Division of A and B is %d \n", division);
    return 0;
}