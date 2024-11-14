#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int size){
    for(int i = size -1; i> 0; i --){
        for (int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
        
    }
}

int main(){

    int arr[] = {4, 5, 2, 6, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);

    for(auto i: arr)
        cout<<i<<"\t";
    
    return 0;
}