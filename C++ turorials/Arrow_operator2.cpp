#include <bits/stdc++.h>

using namespace std;

class Shop{
    int id;
    float price;

    public:
        void set_Data(int a, float b){
            id= a;
            price= b;
        }

        void get_Data(void){
            cout<<"The price of item with ID \""<<id<<"\" is : "<<price<<"\n";
        }
};

int main(){
    cout<<"Enter the numnber of items you want to enter :";
    int n;
    cin>>n;
    Shop *ptr= new Shop[n];
    Shop *ptrTemp= ptr;
    for (int i = 0; i < n; i++)
    {
        int p;
        float q;
        cout<<"Enter the ID of the product: ";
        cin>>p;
        cout<<"Enter the price of the item :";
        cin>>q;
        ptr->set_Data(p,q);
        ptr++;
    }

    ptr= ptrTemp;

    for (int i = 0; i < n; i++)
    {
        ptr->get_Data();
        ptr++;
    }
    delete ptr;
    return 0;
}