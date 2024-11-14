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

    //QUESTION: why did we use Node* get and not a void get()?? 
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
        cout<<"The value of index "<<i<<" is "<<temp->value<<endl;   
    }
};

int main(){

    LL* node = new LL (34);
    node->append(54);
    node->append(97);

    // node->printList();
    node->get(0);
    node->get(1);
    node->get(2);
    node->get(3);
    
    return 0;
}