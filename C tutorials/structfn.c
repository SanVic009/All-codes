# include<stdio.h>
# include<string.h>

struct student
{
    char name[199];
    int roll;
    float cgp;
};

void printinfo(struct student s1);

int main(){
    struct student s1 ={"Reema",234, 9.3};

    printinfo(s1);
    return 0;
}

void printinfo(struct student s1){
    printf("Here is some information about the student :\n");
    printf("Name :%s\n", s1.name);
    printf("Roll number :%d\n", s1.roll);
    printf("cgpa :%f\n", s1.cgp);
}
