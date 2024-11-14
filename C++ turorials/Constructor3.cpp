#include <bits/stdc++.h>

using namespace std;

class Base1{
    int a;
    public:
        Base1(int input){
            a=input;
            cout<<"The constructor of the base class Base1 has been called."<<endl;
        }
        void printVal1(void){
            cout<<"The value sotred in the first class is : "<<a<<endl;
        }
};

class Base2{
    int b;

    public:
        Base2(int x){
            cout<<"The constructor for the base class Base2 has been called."<<endl;
            b=x;
        }
        void printVal2(void){
            cout<<"The value stored in the second base class is : "<<b<<endl;
        }   
};

class Derived: public Base1, public Base2{
    int dog, over;

    public:    
        Derived(int a, int b, int c, int d):Base1(a), Base2(b) {
            dog=c;
            over=d;
            cout<<"The constructor for the derived class has been called."<<endl;
        }
        void printValDerived(void){
            cout<<"The values stored in the derived class is : "<<dog<<" and "<<over<<endl;
        }
};



int main(){

    Derived test(1,2,3,4);
    test.printVal1();
    test.printVal2();
    test.printValDerived();
    return 0;
}