# include<stdio.h>

int main(){
    printf("This program is to know about logic operators");

    printf("This is an and operator 4>2 && 4>3 gives %d \n", 4>2 && 4>3);    //and operator
    printf("This is another operator 4>2 && 3>4 gives %d \n", 4>2 && 3>4);    
    printf("This is a (or) operator 4>2 || 3>4 gives %d \n", 4>2 || 3>4);    //or operator
    printf("This is a use of (not) operator !(4>2 && 3>4) gives %d \n", !(4>2 && 3>4)); // ! stands for not
    return 0;
}