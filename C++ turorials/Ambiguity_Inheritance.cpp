#include <bits/stdc++.h>

using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "Base 1 ::The quick brown fox jumps over the lazy fox"
             << "\n";
    }
};

class Base2
{
public:
    void greet()
    {
        cout << "Base2 ::The quick brown fox jumps over the lazy fox"
             << "\n";
    }
};

class Derived : public Base1, public Base2
{
    int a;
    public:
        void greet(){
            Base2::greet();
        }
};

class Test{
    public:
        void speak(){
            cout<<"This is a test messgae from the base class."<<"\n";
        }
};

class derivedTest: public Test{
    // public:
    //     void speak(){
    //         cout<<"This is the derived class test messgae."<<"\n";
    //     }
};

int main()
{
    // Base1 var1;
    // Base2 var3;

    // Derived x;
    // x.greet();

    Test t;
    derivedTest a;

    a.speak();

    return 0;
}