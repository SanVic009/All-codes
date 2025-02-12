#include<bits/stdc++.h>
#define MAX 101

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
    int binary_r(long int key, int high, int low);
    int binary_nr(long int key, int low, int high);
    void quick_sort(int p, int r);
    int partition(int p, int r);
    void heap();
    void adjust(int n, int i);
};

void Records :: heap(){
    for (int i = users.size()/2 - 1; i >= 0; i--){ 
        adjust(i, users.size());
    }

    for (int i = users.size() - 1; i > 0; i--){
        swap(users[0], users[i]);
        adjust(0, i);
    }
}

void Records::adjust(int n, int i){
    int largest = i;
    int right_c = (2*i) + 1;
    int left_c = (2*i) + 2;

    if(left_c < users.size() && users[left_c].bill_amt > users[largest].bill_amt)
        largest = left_c;
    if(right_c < users.size() && users[right_c].bill_amt > users[largest].bill_amt)
        largest = right_c;
    
    if(largest != i){
        swap(users[i], users[largest]);
        adjust(largest, users.size());
    }
}

void Records::quick_sort(int p, int r){
    if (p < r){
        int q = partition(p, r);
        quick_sort(p, q-1);
        quick_sort(q+1, r);
    }
}

int Records:: partition(int p, int r){
    long int pivot = users[r].mob_no;
    int i = p-1;
    for (int j = p; j < r; j++){
        if(pivot > users[j].mob_no){
            i++;
            swap(users[i], users[j]);
        }
    }
    swap(users[i+1], users[r]);
    return i+1;
}

int Records::binary_nr(long int key, int low, int high){
    
    while(low <= high){
        int mid = (high + low)/2;
        if(users[mid].mob_no == key){
            cout<<"USER FOUND!"<<endl;
            cout<<users[mid].name<<"\t"<<users[mid].mob_no<<"\t"<<users[mid].bill_amt<<endl;
            return mid;
        } else{
            if(key > users[mid].mob_no)
                high = mid-1;
            else
                low = mid +1;
        }

    }
}

int Records::binary_r(long int key, int low , int high){
    int mid = (high + low)/2;
    if(users[mid].mob_no == key){
        cout<<"USER FOUND!"<<endl;
        cout<<users[mid].name<<"\t"<<users[mid].mob_no<<"\t"<<users[mid].bill_amt<<endl;
        return mid;
    }
    else{
        if(key > users[mid].mob_no){
            binary_r(key, mid+1,high);
        }
        else{
            binary_r(key, low, mid-1);
        }
    }
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