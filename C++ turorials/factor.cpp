#include<iostream>

using namespace std;

int main(){
    // beg:
    int n;
    cout<<"Enter the number of which you want to find the factors :\n";
    cin>>n;
    cout<<endl;
    for(int i=1;i<=n;i++){
        if (n%i==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    // goto beg;
    return 0;
}