#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;

    Node (int key , int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class Hash
{
private:
    static const int SIZE = 11;
    Node *dataMap[SIZE];

public:
    int hash(int key)
    {
        int hasher;
        for (int i = 0; i < SIZE; i++)
        {
            hasher = (3*key + 1) % SIZE;
        }
        return hasher;        
    }

    bool itemsInCommon()
    {
        
    }

    // void printTable()
    // {
    //     for (int i = 0; i < SIZE; i++)
    //     {
    //         cout<<i<<":"<<endl;
    //         if(dataMap[i])
    //         {
    //             Node *temp = dataMap[i];
    //             while(temp)
    //             {
    //                 cout<<" {"<<temp->key<<", "<<temp->value<<", "<<" }"<<endl;
    //                 temp = temp->next;
    //             }
    //         }
    //     }
        
    // }

    //chatgpt function
    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ": ";
            if (dataMap[i] != nullptr)
            {
                Node *temp = dataMap[i];
                while (temp != nullptr)
                {
                    cout << "{" << temp->key << ", " << temp->value << "} ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }


    void set(int key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(index,value);
        Node *temp = dataMap[index];
        if(dataMap[index] == nullptr){
            dataMap[index] = newNode;
            return;
        }
        while(temp)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

};

int main(){
    Hash *myHash = new Hash();

    int size1 = 0, size2 = 0;
    vector<int> vec1, vec2;

    cout<<"Specify the size of the first vector: ";
    cin>>size1;
    cout<<"Specify the size of the second vector: ";
    cin>>size2;

    for (int i = 0; i < size1; i++)
    {
        int element;
        cin>>element;
        vec1.push_back(element);
    }

    for (int i = 0; i < size2; i++)
    {
        int element;
        cin>>element;
        vec2.push_back(element);
    }
    
    for (int i = 0; i < size1; i++) myHash->set(vec1[i],1);
    for (int i = 0; i < size2; i++) myHash->set(vec2[i], 2);

    myHash->printTable();
    return 0;
}