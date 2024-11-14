#include <iostream>

using namespace std;

int main()
{
    enum food
    {
        breakfast,
        lunch,
        snacks,
        dinner
    };
    cout << breakfast << endl;
    cout << lunch << endl;
    cout << snacks << endl;
    cout << dinner << endl;
    // enum assignes numbers to the elements which are presrent in it from left to right.
    return 0;
}