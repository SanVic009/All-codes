#include<bits/stdc++.h>

using namespace std;

class Sal{
private:
    int basic, DA, TA;

public:

    int netSalary = 0 ;
    
    void setSalVal(){
        cout<<"Enter the basic salary: ";
        cin>>basic;

        cout<<"Enter the dearness allowance: ";
        cin>>DA;

        cout<<"Enter the travel allowance ";
        cin>>TA;
    }

    void displaySal(){
        cout<<"Basic salary is :"<<basic<<endl;
        cout<<"Dearness allowance is: "<<DA<<endl;
        cout<<"Travel allowance is: "<<TA<<endl;
        cout<<"Net salary is :"<< DA + TA + basic<<endl;
    }
};

class emp{
private:
    int empNo;
    Sal salary;
    string empName, quali, address;
    long contactNumber;

public:
    emp(){
        cout<<"Enter the Employee number: ";
        cin>>empNo;

        cout<<"Enter the name of the employee: ";
        cin>>empName;

        cout<<"Enter the qualification of the employee :";
        cin>>quali;

        cout<<"Enter the contact number: ";
        cin>>contactNumber;
        
        cout<<"Enter the address of the employee: ";
        cin>>address;

        salary.setSalVal();
    }

    void displayVal(){
        cout<<"Emp name :"<<empName<<endl;
        cout<<"Emp number :"<<empNo<<endl;
        cout<<"Emp qualification :"<<quali<<endl;
        cout<<"Emp address :"<<address<<endl;
        cout<<"Emp contact number :"<<contactNumber<<endl;
        salary.displaySal();
    }

    emp(const emp &other){

        cout<<"COPY CONSTRUCTOR HAS BEEN CALLED"<<endl;
        empNo = other.empNo;
        empName = other.empName;
        quali = other.quali;
        address = other.address;
        contactNumber = other.contactNumber;
        salary = other.salary;
    }

    ~emp(){
        cout<<"Destructor has been called."<<endl;
    }

    emp(string n, int enumb, string qualif, string addresses, long long cont){
        
        empName = n;
        empNo = enumb;
        quali = qualif;
        address = addresses;
        contactNumber = cont;
        salary.setSalVal();
    }
};

int main(){
    emp Dhruvin;
    Dhruvin.displayVal();

    emp Sanchit( Dhruvin);
    Sanchit.displayVal();

    string name, quali, address;
    long long cont;
    int enumb;
    cout<<"Enter the Employee number: ";
    cin>>enumb;

    cout<<"Enter the name of the employee: ";
    cin>>name;

    cout<<"Enter the qualification of the employee :";
    cin>>quali;

    cout<<"Enter the contact number: ";
    cin>>cont;
    
    cout<<"Enter the address of the employee: ";
    cin>>address;

    emp Aditya(name, enumb, quali, address, cont);

    Aditya.displayVal();
    return 0;
}