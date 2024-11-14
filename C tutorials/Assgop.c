# include<stdio.h>

int main(){
    int a,b;

    printf("This progream is to do some basic operation on two numbers A and B\v ");

    printf("Please enter A :");
    scanf("%d", &a);

    printf("please enter B :");
    scanf("%d", &b);

    printf("A=A+B is %d \n", a +b);
    printf("A=A*B is %d \n", a *b);
    printf("A=A-B is %d \n", a -b);
    printf("A=A/B is %f \n", a /b);

    //something is not right(for future sanchit)   
    /*hi, it is future sanchit. And the answer is because when the operation is performes, the value of a changes, so we might have to use function in this case which will not alter the value of a every time */ 
    return 0;
}