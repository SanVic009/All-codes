#include<iostream>

using namespace std;

class Employee{
    
    private:
        int a,b,c;
    public:
        int d,e;
        void input(int a1, int b1, int c1);
        void output(){
            cout<<"Their value of a is :"<<a<<endl;
            cout<<"The value of b is :"<<b<<endl;
            cout<<"The value of c is :"<<c<<endl;
            cout<<"The value of d is :"<<d<<endl;
            cout<<"The value of e is :"<<e<<endl;
        }
};

void Employee :: input(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee ban;
    // ban.a=23; cant access the value of a this way as it is private and can be accessed with the function in the class which is input;
    ban.d=32;
    ban.e=324;
    ban.input(1,34,53);
    ban.output();
    return 0;
}