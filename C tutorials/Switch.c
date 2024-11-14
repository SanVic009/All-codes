# include<stdio.h>

int main(){
    int x;
    printf("Please enter the number to check if it is 1 or 2 : ");
    scanf("%d", &x);

    switch (x){
        case 1: printf("The number entered if 1");
        break;

        case 2: printf("The number enters is 2");
        break;
        
        default: printf("The number entered is neither 1 nor 2");
    }
    return 0;
}