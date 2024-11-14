#include <bits/stdc++.h>

using namespace std;

int ObjC()
{
    srand(time(NULL));

    return rand() % 3;
}

int ObjP(char *in)
{
    if (*in == 'rock')
        return 0;
    else if (*in == 'paper')
        return 1;
    else
        return 2;
}

void object(int n)
{
    if (n == 0)
        cout << "rock";
    else if (n == 1)
        cout << "Paper";
    else
        cout << "Scissor";
}

int main()
{
    int n, scoreP , scoreC, itemC, itemP;
    char *in, *name;
    cout << "Player Name : ";
    cin >> name;
    name = (char *)calloc(strlen(name)+1 , sizeof(int));
    cout << "Enter the number of rounds of Rock Paper and Scissors" << endl;
    cin >> n;
    scoreC=0, scoreP=0;
    for (int i = 0; i < n; i++)
    {
        in = (char *)calloc(strlen(in)+1, sizeof(int));
        cout << "Enter rock, paper or scissor :" << endl;
        cin >> in;
        ObjP(in);
        ObjC();
        itemC = ObjC();
        itemP = ObjP(in);
        // cout << name << " - " << object(itemP) << " :: Computer - " << object(itemC) << endl;
        cout<<itemP<<" "<<itemC<<endl;
        if (itemP == 0)
        {
            if (itemC == 1)
                scoreC++;
            else
                scoreP++;
        }
        else if (itemP == 1)
        {
            if (itemC == 2)
                scoreC++;
            else
                scoreP++;
        }
        else if (itemP == 2)
        {
            if (itemC == 0)
                scoreC++;
            else
                scoreP++;
        }
        cout <<"You (" << scoreP << ") : Computer (" << scoreC << ")" << endl;
        free(in);
    }
    return 0;
}
/* 
~~tasks for tomorrow~~
use go to when same objs
use compstr in the funciton to find the input obj
*/