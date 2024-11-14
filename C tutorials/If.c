# include<stdio.h>

int main(){
    int age;
    printf("enter age to check if your an adult or not: ");
    scanf("%d", &age);
    if(age> 18){
        printf("You are an adult \n");
        printf("You a can vote");
    }
    else{
        printf("Not an adult");
    }
    return 0;
}