# include<stdio.h>

//Topic is ptr arithmatic hence the name

int main(){
    int age=33;
    int *ptr=&age;
    printf("ptr=%u\n",ptr);
    ptr++;
    printf("ptr=%u\n", ptr);

    //for float :-

    float price=100;
    float *ptr2=&price;
    printf("ptr 2 is %u\n",ptr2);
    ptr2++;
    printf("next ptr2 is %u\n",ptr2);

    char chat='*';
    char *ptr3=&chat;
    printf("ptr 3 is %u\n",ptr3);
    ptr3++;
    printf("next ptr3 is %u\n",ptr3);
    return 0;
}