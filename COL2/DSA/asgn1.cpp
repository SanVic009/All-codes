#include<bits/stdc++.h>
#define MAX 100

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
    friend class Records;
};



class Records{
private:
    vector<MobileUser> users;

public:
    void accept();
    void display();
    void linear_search(long int key);
    void binary_r(long int key, int high, int low);
};

void Records::binary_r(long int key, int high, int low){

            // cout<<user.name<<"\t"<<user.mob_no<<"\t"<<user.bill_amt<<endl;
}

void Records:: linear_search(long int key){
    for(auto user : users){
        if(user.mob_no == key){
            cout<<user.name<<"\t"<<user.mob_no<<"\t"<<user.bill_amt<<endl;
        }
    }
}

void Records::display(){
    for (auto user: users){
        cout<<user.name << "\t"<<user.mob_no<<"\t"<<user.bill_amt<<endl;
    }
}

void Records :: accept(){
    MobileUser temp;
    
    cout<<"Enter the name of the user: ";
    cin>>temp.name;
    cout<<"Enter the number of the user: ";
    cin>>temp.mob_no;
    cout<<"Enter the bill amount in Rs: ";
    cin>>temp.bill_amt;

    users.push_back(temp);
}


int main(){
    return 1;
}