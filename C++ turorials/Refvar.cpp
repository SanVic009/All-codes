#include<iostream>

using namespace std;

int main(){
    float x = 43;
    float &y = x;
    // value same hai but alag alag naam se bula rahe hai as simple as that
    cout<<x<<endl;
    cout<<&x<<endl;
    cout<<y<<endl;
    cout<<&y<<endl; 
    return 0;
}