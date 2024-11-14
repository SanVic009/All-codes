#include<iostream>

using namespace std;

int main(){
    //typecastin is the process of chaning the data type of a variable such as from int to float or from float to double and so on.
    int a= 45;
    float b=45.46;
    cout<<"the value of (float)a is: "<<(float)a<<endl;
    cout<<"the value of float(a) is: "<<float(a)<<endl;
    cout<<"the value of (int)b is: "<<(int)b<<endl;
    cout<<"the value of int(b) is: "<<int(b)<<endl<<"\n";
    cout<<"the expression is "<<a+b<<endl;
    cout<<"the expression is "<<a+int(b)<<endl;
    cout<<"the expression is "<<a+(int)b<<endl;
    return 0;
}