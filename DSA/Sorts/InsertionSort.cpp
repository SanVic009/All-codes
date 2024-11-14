#include <bits/stdc++.h>

using namespace std;

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j > -1 && temp < array[j])
        {
            array[j + 1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

int main()
{

    int arr[] = {4, 5, 2, 6, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for (auto i : arr)
        cout << i << "\t";
}