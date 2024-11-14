# include<stdio.h>
//fibar means fibbonci with array

int main(){
    int n;
    printf("enter the number of terms desired in the fibonacci sequence :");
    scanf("%d", &n);
    
    int fib[n];
    fib[0]=0;
    fib[1]=1;
    printf("%d \t", fib[0]);
    printf("%d \t", fib[1]);
    for (int i=2; i<n; i++){
        fib[i]=fib[i-1]+fib[i-2];
        printf("%d \t", fib[i]);
    }
    
    return 0;
}