# include<stdio.h>

int main(){
    int x,pr;
    printf("Please enter the number of terms you want in the series:");
    scanf("%d", &x);

    for(int i=0;i<=10;i++){
        pr=x*i;
        printf("%d \n", pr);
    }
    return 0;
}