#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int&b){
    int temp = a; 
    a = b;
    b = temp;
}

void selectionSort(int arr[], int size){

    for(int i = 0; i< size; i++){
        int minIndex=i;
        for(int j = i; j < size; j++){
            if(arr[minIndex]>arr[j])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){

    int arr[] = {4, 5, 2, 6, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, size);

    for(auto i: arr)cout<<i<<"\t";
    return 0;
}