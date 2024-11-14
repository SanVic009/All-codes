# include<stdio.h>

int main(){
    int x, sum=0;
    printf("Please enter the number of terms you want in the series :");
    scanf("%d", &x);
    for (int i = 1;i<=x ; i++)
    {
        sum=sum+i;
    }
    printf(" The sum is %d \n", sum);
    return 0;
}