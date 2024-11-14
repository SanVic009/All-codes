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

public:
    int length;
    LL(int value)
    {
        Node* nNode = new Node(value);
        head = nNode;
        tail = nNode;
        length = 1;
    }

    void prepend(int value){
        Node* nNode = new Node (value);
        if(length == 0){
            head = nNode;
            tail = nNode;
        } else {
            nNode->next= head;
            head = nNode;
        }
        length ++;
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

    bool insert(int index, int value)
    {
        cout<<"index is "<<index<<endl;
        // if(get(index))
        if(index<0 || index > length+1)
        {
            cout<<"Index is out of bound"<<endl;
            return false;
        }
        if(index == 0)
        {
            prepend(value);
            return true;
        }
        if( index == length)
        {
            append(value);
            return true;
        }

        Node * temp= get(index-1);
        
        if(temp == nullptr)
            return false;

        Node* newNode = new Node (value);

        newNode->next = temp->next;
        temp->next = newNode;

        length ++;
        return true;        
    }
};

int main(){
    LL* node = new LL (34);
    node->append(54);
    
    if(node->insert(0,33))cout<<"Operation is successful."<<endl;
    else cout<<"Operatoin is unsuccessful."<<endl;
    node->printList();
    cout<<"The length of the list is: "<<node->length<<endl;

    if(node->insert(1,11))cout<<"Operation is successful."<<endl;
    else cout<<"Operatoin is unsuccessful."<<endl;
    node->printList();
    cout<<"The length of the list is: "<<node->length<<endl;

    if(node->insert(4,55))cout<<"Operation is successful."<<endl;
    else cout<<"Operatoin is unsuccessful."<<endl;
    node->printList();
    cout<<"The length of the list is: "<<node->length<<endl;

    return 0;
}