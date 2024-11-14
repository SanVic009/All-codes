# include<stdio.h>

int main(){
    int x;
    do{
        printf("Please enter a number to check if its even :");
        scanf("%d", &x);

        if(x%2!=0){
            break;
        }else{
            printf("This is an even number \n");
        }
    }while( 1);
    printf("This an odd number.The end");
    return 0;
}