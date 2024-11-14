# include<stdio.h>

int main(){
    int age;
    printf("Enter your age :");
    scanf("%d", &age);

    int *ptr=&age;
    int **age2=&ptr;

    printf("The address of pointer ptr: %p \n",&ptr);
    printf("Pointer ptr is pointing to age whhich is age with address %p and has value %d or %d \n",&age,*ptr,age);
    printf("The address of age 2 is %p \n",*age2);
    printf("The value at age2 is %p \n", &(age2));
    printf("But it is indirectly signalling at age with vaule %d", (**age2)); // ye wala galat value de raha hai
   
    return 0;
}