#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[32];
    float marks;
}a1, a3;


int main(){
    a1.id=23;
    printf("The id of employee 1 is :%d", a1.id);    
    return 0;
}