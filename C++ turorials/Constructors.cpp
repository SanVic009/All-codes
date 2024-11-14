#include <bits/stdc++.h>

using namespace std;

class Complex{
    int a, b;
    public:
        Complex(void);
        void out(){
            cout<< "Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

Complex::Complex(void) // this is a default constructor as it is not taking any values{
{
    a=20;
    b=43;
    cout<<"This is a test message."<<endl;
}

int main(){
    Complex x,y,z;
    x.out();
    y.out();
    z.out();
    return 0;
}