#include <iostream>
#include <string>

using namespace std;

class binary
{
    //all the members are private by default in a class
    string s;

    public:
        void input(void);
        void checkbin(void);
        void ulat(void); //ulat as in ulatna , palatna. It is hindi word not english
        void display(void);
};

void binary::input(void)
{
    cout << "Enter the string :";
    cin >> s;
}

void binary::checkbin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "The string is not in binary format" << endl;
            exit(0);
        }
    }
    cout << "The string is in binary format" << endl;
}

void binary::ulat(){
    for (int i = 0; i < s.length(); i++){
        if (s.at(i)=='0')
        {
            s.at(i)='1';
        }else {s.at(i)='0';}
    }    
}

void binary::display(){
    for (int i = 0; i < s.length(); i++){
        cout<<s.at(i);
    }
    cout<<endl;
}

int main()
{
    binary a;
    a.input();
    a.checkbin();
    a.display();
    a.ulat();
    a.display();
    return 0;
}