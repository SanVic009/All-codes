#include <bits/stdc++.h>

using namespace std;


int main() {
    int arr[] = {5, 2, 9, 1, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    cout << "Array sorted in descending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
