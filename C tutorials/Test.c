# include<stdio.h>

int main(){
    int n;
    printf("enter the number of elements in the loop :");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        printf("[] \n");
    }
    return 0;
}