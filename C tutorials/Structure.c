# include<stdio.h>
# include<string.h>

struct student
{
    int roll;
    char name[199];
    float cgpa;
};


int main(){
    struct student s1;
    s1.cgpa = 10.01;
    strcpy(s1.name,"sanchit");
    s1.roll = 22;

    printf("Name of the student is %s\n", s1.name);
    printf("Roll number of the student is %d\n", s1.roll);
    printf("The cgpa of the student was %f\n", s1.cgpa);
    return 0;
}