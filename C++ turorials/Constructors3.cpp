#include <bits/stdc++.h>

using namespace std;

class BankDeposit
{
    int principal, years, irate;
    double retval;

public:
    BankDeposit(){}
    BankDeposit(int p, int y, double r);
    BankDeposit(int p, int y, int r);
    int out()
    {
        cout << "With principal value of " << principal
            << ", total investment period of " << years << " years with rate of investment @ " << irate << " per annum, the final value of the investment with compound interest is: " << retval << endl;
    }
};

BankDeposit ::BankDeposit(int p, int y, double r)
{
    principal = p;
    years = y;
    irate = r;
    int l = p;
    for (int i = 0; i < years; i++)
    {
        l = l * r;
    }
    retval = l;
}
BankDeposit ::BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    irate = r;
    int l = p;
    for (int i = 0; i < years; i++)
    {
        l = l + (l * r) / 100;
    }
    retval = l;
}

int main()
{
    BankDeposit a1(50000, 5, 1.13), a2(100, 1, 20), a3;
    a1.out();
    a2.out();
    return 0;
}
/*
here, a3 will not run without the first constructor as it will not be able to decide which constructor to call.
if a3 is not declared, then it will run finely without the first constructor but it is a good practice to include it as well.
*/