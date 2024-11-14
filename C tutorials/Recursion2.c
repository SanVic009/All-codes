# include<stdio.h>

int fact(int n);

int main(){
    printf("The product of the numbers is :%d", fact(6));
    return 0;
}

int fact(int n){
    if(n==1){
        return 1;
    }
    int fact2=fact(n-1);
    int factN=fact2 *n;
    return factN;
}