#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int array[], int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
    int x = array[secondIndex];
}

int pivot(int arr[], int pivotIndex, int endIndex)
{
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++)
    {
        if (arr[pivotIndex] > arr[i])
        {
            swapIndex++;
            // swap(arr[swapIndex], arr[i]);
            swap(arr, swapIndex, i);
        }
    }
    swap(arr, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int arr[], int leftIndex, int rightIndex)
{

    if (leftIndex >= rightIndex)
        return;

    int pivotIndex = pivot(arr, leftIndex, rightIndex);

    quickSort(arr, leftIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, rightIndex);
}

int main()
{
    int myArray[] = {4, 6, 1, 7, 3, 2, 5};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    quickSort(myArray, 0, size-1);

    for (auto it : myArray)
    {
        cout << it << "\t";
    }
    return 0;
}