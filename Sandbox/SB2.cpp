#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        vec.push_back(element);
    }

    int queries, index = -1, big_val = vec[size - 1];
    bool is_present = false;

    cin >> queries;
    while (queries--)
    {
        int val;
        cin >> val;

        for (int i = 0; i < size; i++)
        {
            is_present = false;
            if (vec[i] == val)
            {
                index = i;
                is_present = true;
                break;
            }
            else if (vec[i] > val)
            {
                index = i;
                break;
            }
        }

        if (is_present)
            cout << "Yes " << index << endl;
        else
            cout << "No " << index << endl;
    }
    return 0;
}
