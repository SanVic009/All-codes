#include <bits/stdc++.h>

using namespace std;

class User
{
private:
    string name;
    int id;
    vector<int> friends;

public:
    friend class Graph
};

class Graph
{
private:
    User users[20];
    int total_user = 0;

public:
    void create_users()
    {
        cout << "Enter the number of users you want to enter";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            if (total_user >= 20)
            {
                cout << "Users list if full.";
                break;
            }

            cout << "Enter the name";
            cin >> users[i].name;
            users[i].id = total_user;
            total_user++;
        }
    }
};

int main()
{

    return 0;
}