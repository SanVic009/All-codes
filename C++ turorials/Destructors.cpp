#include <bits/stdc++.h>

using namespace std;


class num{
    static int count;
    public:
        num(){
            count++;
            cout<<"Here the constructor is called for object number "<<count<<endl;
        }
        ~num(){
            cout<<"this is where destructor is called "<<endl;
            count--;
        }
};

int num::count =0;
// FIXME: this is important because if we use int count =0, it will create new count for each object in the class. So we have to declre a global variable and use that.

// jo bhi memory constructor ne li thi, wo destructor hata deta hai aur memory free up karta hai.
// It takes no argument nor does it returns any value.
int main(){
    cout<<"We are in the main fumction"<<endl;
    cout<<"Creating first object a1"<<endl;
    num a1;
    {
        cout<<"Now entering the block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num a2,a3;
        cout<<"Now exiting the block"<<endl;
    }
    return 0;
}