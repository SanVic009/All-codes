//TODO: review and understand the set code;
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LL
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    LL(int value)
    {
        Node* nNode = new Node(value);
        head = nNode;
        tail = nNode;
        length = 1;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length ++;
    }

    void printList(void)
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    Node* get(int index)
    {
        if(index<0 || index >=length)
        {
            cout<<"Index "<<index<<" is out of bounds."<<endl;
            return nullptr;
        }
        Node * temp = head;
        int i = 0;
        for (; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;   
    }

    bool set(int index, int value)
    {
        Node* temp = get(index);

        if(temp)
        {
            temp->value= value;
            return true;
        }       
        return false;
    }
};

int main(){
    LL* node = new LL (34);
    node->append(54);
    node->append(994);
    cout<<"Initial list was :"<<endl;
    node->printList();

    if(node->set(2,449))
    {
        cout<<"The value has been replaced successfully."<<endl;
    }else{
        cout<<"There was an error."<<endl;
    }

    cout<<"Final list is :"<<endl;
    node->printList();
    if(node->set(5,449))
    {
        cout<<"The value has been replaced successfully."<<endl;
    }else{
        cout<<"There was an error."<<endl;
    }
    
    return 0;
}