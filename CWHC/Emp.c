#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    int n, i=0;
    char *ptr;
    while (i>3){
        printf("Enter the number of characters of employee id :");
        scanf("%d", n);
        ptr=(char*) calloc(n+1,sizeof(int));
        printf("Enter the employee id :");
        scanf("%c", ptr);
        printf("The id of the employee is :%c\n", ptr);
        free(ptr);
        i++;
    }
    return 0;
}