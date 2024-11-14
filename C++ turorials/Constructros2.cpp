#include <bits/stdc++.h>

using namespace std;

class Complex{
    int a, b;
    public:
        Complex(int n=1, int m=23){
            a=n;
            b=m;
        }
        void out(){
            cout<< "Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

int main(){
    Complex x(2),y(2,45),z;
    x.out();
    y.out();
    z.out();
    return 0;
}