#include <iostream>

using namespace std;

class Sal
{
private:
    int basic, DA, TA;

public:
    int netsalary = 0;

    void setSalVal()
    {
        cout << "Enter the basic salary: ";
        cin >> basic;

        cout << "Enter the dearness allowance: ";
        cin >> DA;

        cout << "Enter the travel allowance ";
        cin >> TA;
    }

    void display()
    {
        cout << "Basic salary is : " << basic << endl;
        cout << "Dearness allowance is : " << DA << endl;
        cout << "Travel allowance is : " << TA << endl;
        cout << "Net salary is : " << DA + TA + basic << endl;
    }
};

class emp
{
private:
    int empNo;
    Sal salary;
    string empName, quali, address;
    long contactNumber;

public:
    emp()
    {
    }
};

int main()
{
    return 0;
}