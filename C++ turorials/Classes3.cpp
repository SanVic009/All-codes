#include<iostream>
#include<string>

using namespace std;

class shop{
    int itmID[100];
    int itmprice[100];
    int counter;
    public:
        void initCounter(void){
            counter=0;
        }     
        void inPrice(void);
        void dispPrice(void);
};

void shop::inPrice(void){
    cout<<"Enter the ID of the item no."<<counter+1<<":"<<endl;
    cin>>itmID[counter];
    cout<<"Enter the price of the item no."<<counter+1<<":"<<endl;
    cin>>itmprice[counter];
    counter++;
}

void shop::dispPrice(void){
    for (int i = 0; i < counter; i++)
    {
        cout<<"The item with item ID "<<itmID[i]<<" has price "<<itmprice[i]<<endl;
    }
    
}

int main(){
    shop dukan;
    dukan.initCounter();
    int n;
    cout<<"Specify the number of entries :";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        dukan.inPrice();
    }
    dukan.dispPrice();
    return 0;
}