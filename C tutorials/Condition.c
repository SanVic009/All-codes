# include<stdio.h>

int main(){
    int age;
    printf("Please enter your age to check if you are adult or not: ");
    scanf("%d", &age);
    (age>=18)?
        printf("You are an adult"):
        printf("You are not an adult");
    return 0;
}