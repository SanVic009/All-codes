# include<stdio.h>

int main(){
    int age=33;
    int *ptr= &age;
    int age2 = *ptr;
//agar _age gives value of value at age due to appropriate syntax, why does age not give value at memory named 33

//maybe because age is not a pointer
    printf("The value at age2 is %d \n", age2);
    printf("address of ptr in hexadecimal form is :%p \n", &ptr);
    printf("Address of age2 in unsigned int form is :%u", age2);
    return 0;
} 
//for value at address , use astersik and use %d;
//for the address, use &;