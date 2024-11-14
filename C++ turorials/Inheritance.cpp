#include <bits/stdc++.h>

using namespace std;

// base class
class employee
{
    public:
        int id;
        float salary;
        employee(){}
        employee(int inpID)
        {
            id = inpID;
            salary = 32;
        }
};

// derived class
//--> default visibility mode is private.
//--> visibility matlab base class ki public members aapki derived class ke kaunse part (private ya public) me jayenge.
//--> visibility private means base class ke public members derived class ke private members ban jayenge and so on.
//--> you CANNOT inherit private members of the base class in the derived class.
class programmer : public employee
{
public:
    int langCode;
    programmer(int inpID)
    {
        id = inpID;
        langCode = 49;
    }
    void out()
    {
        cout << id << endl;
    }
};

int main()
{
    employee ram(1), shyam(2);
     
    cout << ram.salary << endl;
    cout << ram.id << endl;
    cout << shyam.salary << endl;
    cout << shyam.id << endl;

    programmer skill(354);
    skill.out();
    cout<<skill.langCode<<"\n";
    return 0;
}

/*
                Types
    Single inheritance:- ek se dusra ban gaya
            -> employee  se programmer bana
    Multiple inheritance:- ek derived class hai uske more than one base class hai.
            -> employee aur server engineer se programer bana
    Heirarchial inheritance:- ek base class ke more than one derived classes.
            -> employee se programmer and technician bana.(oppostie of multiple inheritance)
    Multilevel inheritance:- deriving a class from a derived class.
            -> employee se programmer derive hua and programmer se developer derive hua
    Hybrid inheritance:- mixture of multiple, heirarchial inheritance and multilevel inheritance
*/