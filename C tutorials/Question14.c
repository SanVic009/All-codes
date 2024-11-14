# include<stdio.h>
# include<math.h>

int main(){
    int n;
    printf("Please enter your number to find its square:");
    scanf("%d", &n);

    printf("%f", pow(n,0.5));
    return 0;
}