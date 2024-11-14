# include<stdio.h>

int main(){
    int i, j=0;
    printf("Please enter the number of terma you want in the series:");
    scanf("%d", &i);
    for(int k=0;k<=i;k++){
        printf("%d \n", k);
    }
    while (j<=i )
    {
        printf("%d \n", j);
        j++;

    }
    return 0;
}