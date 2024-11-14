#include <bits/stdc++.h>

using namespace std;

class Base1{
    protected:
        int base1var;
    public:
        void setVar1(int a){
            base1var=a;
        }
};

class Base2{
    protected:
        int base2var;
    public:
        void setVar2(int b){
            base2var=b;
        }
};

class Derived : public Base1, public Base2
{
    public:
        void display(){
            cout<<"The value of vairable in the base 1 is :"<<base1var<<"\n";
            cout<<"The value of vairable in the base 2 is :"<<base2var<<"\n";
        }
};

int main(){
    Derived test;

    //FIXME: I cannot use (.) operator for test.setVar1. find the bug. 

    return 0;
}