#include<iostream>
#include<string>

using namespace std;

class Employee{
        int id;
        int salary;
        int t;

    public:
        void entries(void);
        void setID(void);
        void getID(void);
};

void Employee::setID(void){
    salary =122;
    cout<<"Enter the id of employee"<<endl;
    cin>>id;
}

void Employee::getID(void){
    cout<<"THe id of the employee is :"<<id<<endl;
}

void Employee::entries(void){
    cout<<"Enter the numbers of entries :";
    cin>>t;
}

int main(){
    int t;
    // cout<<"Enter the numbers of entries"<<endl;
    // cin>>t;
    Employee jcb[t];
    for (int i = 0; i <4; i++)
    {
        jcb[i].setID();
    }
    // jcb[]
    
    return 0;
}