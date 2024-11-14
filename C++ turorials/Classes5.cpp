#include <bits/stdc++.h>

using namespace std;


// Properties of friend functions
// 1. Not in the scope of class
// 2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
// 3. Can be invoked without the help of any object
// 4. Usually contans the objects as arguments
// 5. Can be declared inside public or private section of the class
// 6. It cannot access the members directly by their names and need object_name.member_name to access any member.
class Complex{
    int a,b;
    friend Complex add(Complex m, Complex n);
    public:
        void input(int x, int y){
            a=x;
            b=y;
        }
        void print(){
            cout<<"The number is "<<a<<" + "<<b<<"i\n";
        }
};

Complex add(Complex m, Complex n){
    Complex o;
    o.input((n.a+m.a),(n.b+m.b));
    return o;
}

int main(){
    Complex n1, n2, sum;
    n1.input(3,5);
    n2.input(3,6);

    n1.print();
    n2.print();

    sum = add(n1,n2);
    sum.print();

    return 0;
}
