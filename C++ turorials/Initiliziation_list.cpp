#include <bits/stdc++.h>

using namespace std;

class Base
{
    int a, b;

public:
    // Base(int i, int j) : a(i), b(j)
    // Base(int i, int j) : a(i), b(j+a)
    // Base(int i, int j) : a(i), b(j+i)
    // Base(int i, int j) : b(j), a(i+b) is not valid because here, a is intilized first. If b was intilized first, then it would have been valid syntax.
    Base(int i, int j) : a(i), b(j+i)
    {
        cout << "The constructor has been called." << endl;
        cout << "The value of a is : " << a << endl;
        cout << "The value of b is : " << b << endl;
    }
};

int main()
{

    Base test(1, 3), test3(4, 6);

    return 0;
}