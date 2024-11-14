# include<stdio.h>
# include<string.h>

struct student
{
    char name[199];
    int roll;
    float cgpa;
};

int main(){
    struct student s1;
    s1.roll =11;
    strcpy(s1.name,"NAme1");
    s1.cgpa= 9.01;

    struct student s2 ={"Reema",234, 9.3};
    struct student s3 ={"Seema",235, 8.3};
    struct student s4 ={0};
    printf("%d\n", s1.roll);
    printf("%s\n", s1.name);
    printf("%f\n\n", s1.cgpa);
   
    printf("%d\n", s2.roll);
    printf("%s\n", s2.name);
    printf("%f\n\n", s2.cgpa);
   
    printf("%d\n", s3.roll);
    printf("%s\n", s3.name);
    printf("%f\n\n", s3.cgpa);

    printf("%d\n", s4.roll);
    printf("%s\n", s4.name);
    printf("%f\n\n", s4.cgpa);
    return 0;
}