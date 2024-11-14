#include <iostream>
using namespace std;

template <typename T>
class BubbleSort
{
public:
    void sort(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BubbleSort<int> intSort;
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int nInt = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Original integer array: ";
    intSort.display(intArr, nInt);

    intSort.sort(intArr, nInt);

    cout << "Sorted integer array: ";
    intSort.display(intArr, nInt);

    BubbleSort<float> floatSort;
    float floatArr[] = {64.5, 34.3, 25.1, 12.8, 22.7, 11.5, 90.2};
    int nFloat = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "\nOriginal float array: ";
    floatSort.display(floatArr, nFloat);

    floatSort.sort(floatArr, nFloat);

    cout << "Sorted float array: ";
    floatSort.display(floatArr, nFloat);

    return 0;
}