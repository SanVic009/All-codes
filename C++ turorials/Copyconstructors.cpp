#include <bits/stdc++.h>

using namespace std;

class Number
{
    int a;

    public:
        Number() { a = 0; }
        Number(int x)
        {
            a = x;
        }
        Number(Number &i)
        {
            cout << "Copycons called" << endl;
            a = i.a;
        }
        void out()
        {
            cout << "The number is :" << a << endl;
        }
};

int main()
{
    Number x, y, z, z2(x);
    x.out();
    y.out();
    z.out();
    z2.out();
    return 0;
}
// Agar ham copycons wala function hata bhi dete hai tab bhi error nahi aat hai because compiler ek default compiler sabko deta hai when no copy costructor is found.