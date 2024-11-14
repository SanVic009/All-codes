#include <iostream>

using namespace std;

template <class T>
void swp(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void bubble(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swp(arr[j], arr[j + 1]);
        }
    }
}

template <class T>
void display(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 4, 5, 1, 5, 10};
    float ar[] = {23.31, 23.08, 23.09, 23.44, 23.88, 23.51};

    int size = 6;
    bubble(arr, size);
    bubble(ar, size);

    display(arr, size);
    display(ar, size);

    return 0;
}