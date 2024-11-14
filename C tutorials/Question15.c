# include<stdio.h>

void sq(int n);
void sq2(int *n);

int main(){
    int x=4;

    sq(x);
    printf("The number is :%d\n", x);

    sq2(&x);
    printf("The number is :%d\n",x);
    
    return 0;
}

void sq(int n){
    n=n*n;
    printf("The sqare number is :%d \n",n);
}

void sq2(int *n){
    *n=(*n)*(*n);
    printf("The square is: %d \n", *n);
}