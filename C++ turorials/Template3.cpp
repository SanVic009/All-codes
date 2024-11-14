#include <bits/stdc++.h>

using namespace std;

template <class F1 = int, class F2 = float, class F3 = char>
class Test
{
public:
    F1 a;
    F2 b;
    F3 c;
    Test(F1 i, F2 j, F3 k){
        a = i;
        b = j;
        c = k;
    }

    void display ()
    {
        cout<<"The value of A is :"<<a<<endl;
        cout<<"The value of B is :"<<b<<endl;
        cout<<"The value of C is :"<<c<<endl;
    }
};

int main()
{
    Test<> v1(1, 3.5, 'g');
    v1.display();
    cout<<endl;
    Test<int, int, int> v2(2,3,4);
    v2.display();
    return 0;
}