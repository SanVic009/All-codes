#include <bits/stdc++.h>

using namespace std;

class Complex
{
    int real, imaginary;

public:
    void set_Date(int a, int b)
    {
        real = a;
        imaginary = b;
    }

    void get_Data(void)
    {
        cout << "The real part is " << real << ".\nThe imaginary part is " << imaginary << ".\n";
    }
};

int main()
{

    Complex *ptr = new Complex;

    ptr->set_Date(5, 6);
    ptr->get_Data();
    
    return 0;
}