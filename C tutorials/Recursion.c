# include<stdio.h>

int sum(int n);

int main(){
    int n;
    printf("To find the sum, specify the number :");
    scanf("%d", &n);
    printf("The sum of specified natural numbers is :%d", sum(n));
    return 0;
}

int sum(int n){
    if(n==1){
        return 1;
    }
    int sum2 = sum(n-1);
    int sumN = sum2+n;
    return sumN;
}