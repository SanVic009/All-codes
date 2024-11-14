#include <stdio.h>

// int ret(int x);

int main()
{
    // int x;
    // printf("enter the total number of items");
    // scanf("%d", &x);
    int items[5];
    int *ptr = &items[0];
    printf("%p \n", &ptr);
    printf("%d\n", ptr);
    printf("%d\n", &ptr);
    printf("%d \n", *ptr);
    // for(int i = 0; i <5; i++)
    // {
    //     printf("enter the price of item no %d :", i+1);
    //     scanf("%d \n", (&ptr+i));
    // }
    // for(int i=0;i<5;i++){
    //     printf("The amount of the item number %d with added gst is :%d \n",i+1,items[i]);
    // }
    // return 0;
}
// yaha ek extra entry aa rahhi hai jo ki 2 ko assigh ho rahi hi but 5 wali entry gayab ho rahi hai

// int ret(int x){
//     return x+1;
// }
// //try using count in future