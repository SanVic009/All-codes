# include<stdio.h>

void swap(int a, int b);
void swapr(int *a,int *b);

int main(){
    int a,b;
    printf("Enter 2 numbers to be swapped\n");
    printf("Enter number a :");
    scanf("%d",&a);

    printf("Enter number b :");
    scanf("%d", &b);

    printf("Originally the a and  b are %d and %d \n \n", a,b);

    swap(a,b);
    printf("Value of a is %d while b is %d outside the swap function\n \n",a,b);

    swapr(&a, &b);
    printf("The value of  a is %d and value of b is %d",a,b);
    return 0;
}
//call by value

void swap(int a, int b){
    int t=a;
    a=b;
    b=t;
    printf("the value in the function swap is %d(a), %d(b)\n \n",a,b);
}

//call by referrence

void swapr(int *a, int *b){
    int t=*b;
    *b=*a;
    *a=t;
    printf("The value of a and b in the funbction swapr is %d %d resp\n \n",*a,*b);
}