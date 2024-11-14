#include <stdio.h>
struct student
{
    int roll;
    int div;
    float percent;
    char name[20];
    char address[50];
    
}s[50];

int main()
{
    for(int i = 0;i<=50;i++){
    printf("Enter Roll No : \n");
    scanf("%d", &s[i].roll);

    printf("Enter Div : \n");
    scanf("%d", &s[i].div);

    printf("Enter Percentage : \n");
    scanf("%f", &s[i].percent);

    printf("Enter Name : \n");
    scanf("%s", s[i].name);
    printf("Mai Gadha hu\n");
    printf("Enter address : \n");
    scanf("%s", s[i].address);

    printf("Name is : %s\n", s[i].name);
    printf("Roll No is : %d\n", s[i].roll);
    printf("Division is : %d\n", s[i].div);
    printf("Percentage is : %f\n", s[i].percent);
    printf("Address is : %s\n",s[i].address);
    }
}