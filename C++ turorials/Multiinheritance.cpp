#include <bits/stdc++.h>

using namespace std;

class Student
{
protected:
    int rollNumber;

public:
    void setRollNumber(int r)
    {
        rollNumber = r;
    }
    void getRollNumber(void)
    {
        cout << "The Roll Number is " << rollNumber << "\n";
    }
};

class Exam : public Student
{
protected:
    float maths;
    float phy;

public:
    void setMarks(float m1, float m2)
    {
        maths = m1;
        phy = m2;
    }
    void getMarks()
    {
        cout << "The marks scored in maths are " << maths << "\n";
        cout << "The marks scored in physics are " << phy << "\n";
    }
};

class result : public Exam{
    float percentage;

public:
    void displayResult(){
        getRollNumber();
        getMarks();
    }
};

int main()
{
    int roll, marksMaths, marksPhy;

    cout<<"Enter the roll number :";
    cin>>roll;
    cout<<"Enter the marks of maths and physics :";
    cin>>marksMaths;
    getchar();
    cin>>marksPhy;
    result Manny;
    Manny.setRollNumber(roll);
    Manny.setMarks(marksMaths, marksPhy);
    Manny.displayResult();
    return 0;
}