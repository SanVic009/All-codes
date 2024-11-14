# include<stdio.h>

int main(){
    int age=11,age2=22;
    int *ptr=&age;
    int *ptr2=&age2;

    printf("The difference between the pointers is %u \n", ptr-ptr2);
    printf("%u %u\n",ptr,ptr2);

    printf("the comparison between the 2 pointers is %d",ptr==ptr2);
    return 0;
}