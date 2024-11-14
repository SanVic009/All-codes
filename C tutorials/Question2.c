# include<stdio.h>

int main(){
    int marks,a;
    printf("Please enter your marks to check your grade: ");
    scanf("%d", &marks);

    if ( (marks <= 100) && (marks >= 90))
    {
        a=1;
    }
    else if ((marks>=70) && (marks <90))
    {
        a=2;
    }
    else if ((marks < 70) && (marks >=30))
    {
        a=3;
    }
    else if ((marks < 30) && (marks >=0))
    {
        a=4;
    }
    else{
        printf("Please enter valid marks");
    }    
    switch ( a )
    {
    case 1: printf("A+");
        break;

    case 2: printf("A");
        break;

    case 3: printf("B");
        break;

    case 4: printf("C");
        break;
    default: printf("The system has encountered a problem");
        break;
    }
    return 0;
}