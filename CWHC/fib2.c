# include<stdio.h>
# include<string.h>

int fib(int a);

int main(){
    int a;
    printf("Enter the number of terms in the fibonacci sequence :");
    scanf("%d", &a);

    fib(a);
    return 0;
}

int fib(int a){
    if((a==1)||(a==2)){
        printf("%d", a-1);
    }
}