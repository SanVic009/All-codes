#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    int temp = a; 
    a = b;
    b = temp;
}

void swap(int array[], int firstIndex, int secondIndex){
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
    int x = array[secondIndex];
}

int pivot(int pivotIndex, int arr[], int endIndex){
    int swapIndex = pivotIndex;
    for(int i = pivotIndex + 1; i <= endIndex; i ++){
        if(arr[pivotIndex]> arr[i]){
            swapIndex++;
            // swap(arr[swapIndex], arr[i]);
            swap(arr, swapIndex, i);
        }
    }
    swap(arr, pivotIndex, swapIndex);
    return swapIndex;
}

int main(){
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int returnIndex = pivot(0, myArray, size -1);
    cout<<"Returnde Index is: "<<returnIndex<<endl;

    for(auto it : myArray){
        cout<<it<<"\t";
    }
    return 0;
}