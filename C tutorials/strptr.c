# include<stdio.h>
# include<string.h>

struct student
{
    char name[199];
    int roll;
    float cgpa;
};

int main(){
    struct student s2 ={"Reema",234, 9.3};
    printf("the roll number of the student is : %d\n", s2.roll);

    struct  student *ptr =&s2;
    printf("the roll number of the student using pointers is : %d\n", (*ptr).roll);
    //here, *(ptr).roll is invalid as well as *ptr.roll
    printf("the roll number of the student using pointers -> is : %d\n", ptr->roll);
    //for simplicity, you can use the last one more
    return 0;
}