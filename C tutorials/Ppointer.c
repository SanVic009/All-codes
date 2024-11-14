# include<stdio.h>

int main(){
    int x=5;
    int *ptr=&x;
    int **ptr2=&ptr;

    printf("%d", **ptr2);
    return 0;
}