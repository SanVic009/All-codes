#include <iostream>
#include <vector>
#include <list>

using namespace std;

void displayList(list<int> &ls)
{
    list<int>::iterator it;
    for (it = ls.begin(); it != ls.end(); it++)
    {
        cout << *it << "\t";
    }
    cout<<endl;
}

int main()
{

    // list<int> ls;
    // int ls_len;
    // cout << "Enter the length of the list here: ";
    // cin >> ls_len;
    // // list<int>::iterator it;

    // for (int i = 0; i < ls_len; i++)
    // {
    //     int element;
    //     cin >> element;
    //     ls.push_back(element);
    // }
    // displayList(ls);

    // ls.pop_back();
    // displayList(ls);

    // ls.pop_front();
    // displayList(ls);

    
    list <int> lst(5);
    
    //NOTE: The output of cout<<*iter<<endl; depend on whether the list has been resized due to adding an element to the front

    lst.push_front(5);
    list <int> :: iterator iter= lst.begin();
    cout<<*iter<<endl;

    // for(int i = 0;iter!= lst.end(); iter ++, i++)
    // {
    //     lst.push_back(i);
    //     cout<<*iter<<" "<<i<<endl;;
    // }
    // displayList  (lst);

    
    return 0;
}