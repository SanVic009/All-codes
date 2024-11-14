#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Node 
{
public:
    string key;
    int value;
    Node *next;

    Node (string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class Hash {
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue *23) % SIZE;
        }
        return hash;
    }

    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout<<i<<":"<<endl;
            if(dataMap[i])
            {
                Node *temp = dataMap[i];
                while(temp)
                {
                    cout<<"  {"<<temp->key<<", "<<temp->value<<"}"<<endl;
                    temp = temp->next;
                }
            }
        }
        
    }

    void set(string key, int value)
    {
        int index = hash (key);
        Node *newNode = new Node (key, value);
        if(dataMap[index] == nullptr)
            dataMap[index] = newNode;
        else{
            Node *temp = dataMap[index];
            while(temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
};

int main(){
    Hash *myTable = new Hash ();

    myTable->set("Oregano", 32);
    myTable->set("Chilli", 64);
    myTable->set("Olives", 54);
    myTable->set("Capsicum", 54);


    myTable->printTable();
    return 0;
}