# include<stdio.h>

int dg(int n);

int main(){
    int n;
    printf("Please enter your number to find its sum if digits:");
    scanf("%d", &n);

    printf("The sum of its digits is :%d", dg(n));

    return 0;
}

int dg(int n){
    int t= (int)n/10;
    int o=n-(t*10);
    return o+t;
}