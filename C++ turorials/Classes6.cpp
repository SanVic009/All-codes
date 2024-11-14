#include <bits/stdc++.h>

using namespace std;

class Complex;

class calculator{
    public:
        int sum ( int a, int b){
            return a+b;
        }
        int addc(Complex , Complex);
        int addr(Complex, Complex);
};

class Complex{
    int a,b;
    friend class calculator;
    // friend int calculator:: addr(Complex m, Complex n);
    // friend int calculator:: addc(Complex m, Complex n);
    public:
        void input(int x, int y){
            a=x;
            b=y;
        }
        void print(){
            cout<<"The number is "<<a<<" + "<<b<<"i\n";
        }
};

int calculator:: addr(Complex m, Complex n){
    return (m.a+n.a);
}


int calculator:: addc(Complex m, Complex n){
    return (m.b+n.b);
}

int main(){ 
    Complex n1, n2;
    n1.input(3,6);
    n2.input(5,6);

    calculator calc;

    int r= calc.addr(n1,n2);
    int c= calc.addc(n1,n2);

    cout<<"The sum of the real part of the n1 and n2 is "<<r<<endl;
    cout<<"The sum of the real part of the n1 and n2 is "<<c<<endl;
    return 0;
}