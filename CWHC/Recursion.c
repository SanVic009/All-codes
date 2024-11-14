# include<stdio.h>
# include<string.h>

int factorial(int n);

int main(){
    int n;
    printf("Enter the number of which you want to find factorial : ");
    scanf("%d", &n);

    printf("The factorial of %d is %d",n ,factorial(n));
    return 0;
}

int factorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }else { 
        return (n * factorial(n-1));
    }
}