#include <bits/stdc++.h>

using namespace std;

void entry(int a_rows,int a_columns, int b_rows, int b_columns){
    int k= a_rows+1;
    while(a_rows--){
        cout<<"Enter the elemts in row "<<k-a_rows<<endl;
        while(a_columns--){
            
        }
    }
}

void multiplication(){

}

int main(){
    int a_rows, a_columns, b_rows, b_columns;
    cout<<"Enter the numbers of rows and columns for A matrix :"<<endl;
    cin>>a_rows>>a_columns;
    cout<<"Enter the numbers of rows and columns for B matrix :"<<endl;
    cin>>b_rows>>b_columns;
    if(a_columns!=b_rows){
        cout<<"These matrices cannot be multiplied.";
    }else{
        entry(a_rows,a_columns, b_rows, b_columns);
        multiplication();
    }
    return 0;
}