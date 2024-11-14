#include <iostream>

using namespace std;

union money
{
    int rice;
    char car;
    float rupees;
};

int main()
{
    // union is used to save memory. It is like structure only but we can allot value to only one of the
    union money rohan;
    rohan.rice = 30;
    union money honey;
    honey.car = 'c';
    honey.rice = 4;
    cout << rohan.car << endl
         << honey.rice;
    // the value which is asiighned later will be considered and the former value will be nullified.
    return 0;
}