#include<iostream>
#include <unordered_map>
#include<vector>

using namespace std;

class Friends{
private:
    string Name;
    Friends* next;

    Friends(string name){
        this->Name = name;
        this->next = nullptr;
    }
};

class User{
private:
    unordered_map< string , Friends> adjList;

public:
    // User(int n){
    //     cout<<"Enter the number of users in the list :"<<endl;
    //     cin>>n;

    //     for (int i = 0; i < n; i ++){
    //         cout<<"Enter the name of user "<< i<<endl;
    //         string name;

    //         Friends fr();



    //     }
    // }

    bool add_user(string name){
        if(adjList.count(name) == 0){
            adjList[name];
            return true;
        }
        return false;

    }
    
    void append_friend(){
        
    }
};


int main(){
    return 0;
}