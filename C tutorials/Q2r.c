# include<stdio.h>

int main(){
    int marks;
    printf("Please enter your marks to check your grade: ");
    scanf("%d", &marks);

    if ( (marks <= 100) && (marks >= 90))
    {
        printf("You got A+");
    }
    else if ((marks>=70) && (marks <90))
    {
        printf("You got A");
    }
    else if ((marks < 70) && (marks >=30))
    {
        printf("You got B");
    }
    else if ((marks < 30) && (marks >=0))
    {
        printf("You got C");
    }
    else{
        printf("Please enter valid marks");
    }
    return 0;
}