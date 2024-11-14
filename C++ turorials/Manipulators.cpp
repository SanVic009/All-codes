#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    //we have used iomanip header for this one
    int a=4, b=45, v=4535, h= 53453;
    cout<<"The value wihtiout setw is: "<<a<<endl;
    cout<<"The value wihtiout setw is: "<<b<<endl;
    cout<<"The value wihtiout setw is: "<<v<<endl;
    cout<<"The value wihtiout setw is: "<<h<<endl;
    cout<<"The value with setw is: "<<setw(4)<<a<<endl;
    cout<<"The value with setw is: "<<setw(4)<<b<<endl;
    cout<<"The value with setw is: "<<setw(4)<<v<<endl;
    cout<<"The value with setw is: "<<setw(4)<<h<<endl<<"****the last one is important as it tells that it is alligned to the fouth letter and does not omit any letter****";
    return 0;
}