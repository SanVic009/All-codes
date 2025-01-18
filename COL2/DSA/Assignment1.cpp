#include <iostream>
#include <stdlib.h>
using namespace std;

class MobileUser
{
    long int mob_no;
    string name;
    long int bill_amt;

public:
    MobileUser()
    {
        mob_no = 0;
        name = "";
        bill_amt = 0;
    }
    friend class records;
};

class records
{
    MobileUser M[10];
    int n;

public:
    records(int n1)
    {
        n = n1;
    }
    void accept();
    void display();
    int linear_search(long int key);
    int binary_r(long int key, int low, int high);
    int binary_nr(long int key, int low, int high);
    void heap_sort();
    void adjust(int n1, int i);
    int partition(int p, int r);
    void quick_sort(int p, int r);
};

void records::accept()
{
    cout << "Enter mob_no., name, bill_amt" << n << endl;
    for (int i = 0; i < n; i++)
        cin >> M[i].mob_no >> M[i].name >> M[i].bill_amt;
}

void records::display()
{
    cout << "Mob_no\t name\t Bill\t" << endl;
    for (int i = 0; i < n; i++)
        cout << M[i].mob_no << "\t" << M[i].name << "\t" << M[i].bill_amt << endl;
}

int records::linear_search(long int key)
{
    for (int i = 1; i < n; i++)
    {
        cout << "Pass: " << i << ", Checking: " << M[i].mob_no << endl;
        if (key == M[i].mob_no)
        {
            cout << "Mob_no: " << M[i].mob_no << ", Name: " << M[i].name << ", Bill: " << M[i].bill_amt << endl;
            return i;
        }
    }
    return -1;
}

int records::binary_r(long int key, int low, int high)
{
    int mid;
    mid = (low + high) / 2;
    if (low <= high)
    {
        mid = (low + high) / 2;
        cout << "Pass: low = " << low << ", mid = " << mid << ", high = " << high << ", Checking: " << M[mid].mob_no << endl;
        if (key == M[mid].mob_no)
        {
            cout << "Mob_no: " << M[mid].mob_no << ", Name: " << M[mid].name << ", Bill: " << M[mid].bill_amt << endl;
            return mid;
        }
        else if (key < M[mid].mob_no)
            return binary_r(key, low, mid - 1);
        else
            return binary_r(key, mid + 1, high);
    }
    return -1;
}

int records::binary_nr(long int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << "Pass: low = " << low << ", mid = " << mid << ", high = " << high << ", Checking: " << M[mid].mob_no << endl;
        if (M[mid].mob_no == key)
        {
            cout << "Mob_no: " << M[mid].mob_no << ", Name: " << M[mid].name << ", Bill: " << M[mid].bill_amt << endl;
            return mid;
        }
        else if (key < M[mid].mob_no)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void records::adjust(int i, int size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && M[left].bill_amt > M[largest].bill_amt)
    {
        largest = left;
    }
    if (right < size && M[right].bill_amt > M[largest].bill_amt)
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(M[i], M[largest]);
        adjust(largest, size);
    }
}

void records::heap_sort()
{
    int passes = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        adjust(i, n);
        passes++;
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(M[0], M[i]);
        adjust(0, i);
        passes++;
    }
    cout << "Total Passes: " << passes << endl;
}

// 2 8 3 7 4
// 2 3 8 7 4
// 2 3 4 8 7

int records::partition(int p, int r)
{
    MobileUser pivot = M[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (M[j].mob_no < pivot.mob_no)
        {
            i++;
            swap(M[i], M[j]);
        }
    }
    swap(M[i + 1], M[r]);
    return (i + 1);
}

void records::quick_sort(int p, int r)
{
    static int passes = 0;
    if (p < r)
    {
        int q = partition(p, r);
        passes++;
        quick_sort(p, q - 1);
        quick_sort(q + 1, r);
    }
    if (p == 0 && r == n - 1)
    {
        cout << "Total Passes: " << passes << endl;
        passes = 0;
    }
}

int main()
{
    int n;
    long int key;
    int index;
    int ch;
    cout << "Enter no. of records\n";
    cin >> n;
    records r(n);
    r.accept();
    r.display();
    while (1)
    {
        cout << "\n1. Linear Search";
        cout << "\n2. Binary Search(r)";
        cout << "\n3. Binary Search(nr) ";
        cout << "\n4. Heap Sort";
        cout << "\n5. Quick Sort ";
        cout << "\n6. Exit\n";
        cout << "Enter choice\n";
        cin >> ch;
        if (ch == 6)
            exit(0);
        switch (ch)
        {
        case 1:
        {
            cout << "Enter mob_no to search: ";
            cin >> key;
            int index = r.linear_search(key);
            if (index != -1)
                cout << "The mobile no. " << key << " found at index: " << index << endl;
            else
                cout << "The mobile no. " << key << " doesn't exist\n";
            break;
        }
        case 2:
        {
            cout << "Enter the mobile number to search: ";
            cin >> key;
            int result = r.binary_r(key, 0, n - 1);
            if (result == -1)
            {
                cout << "Record not found!" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter the mobile number to search: ";
            cin >> key;
            int resultn = r.binary_nr(key, 0, n - 1);
            if (resultn == -1)
            {
                cout << "Record not found!" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Sorted bill_amt in ascensing order is :\n ";
            r.heap_sort();
            r.display();
            break;
        }
        case 5:
        {
            cout << "Sorted mob_no in descending order is : \n";
            r.quick_sort(0, n - 1);
            r.display();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}