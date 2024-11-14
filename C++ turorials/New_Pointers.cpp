#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int *ptr= new int(34);
    cout<<"THE new value is "<< *ptr<<endl;

    int *arr= new int[3];
    arr[0]=23;
    *(arr+1)=34;
    *(arr+2)= 345;

    cout<<"The values of arr[0] is : "<< arr[0]<<endl;
    cout<<"The values of arr[1] is : "<< arr[1]<<endl;
    cout<<"The values of arr[2] is : "<< arr[2]<<endl;

    return 0;
}