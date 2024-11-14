#include <iostream>

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

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {  
        cout<<"Constructor is called."<<endl;
        Node *nNode = new Node(value);
        head = nNode;
        tail = nNode;
        length = 1;
    }

    ~LinkedList()
    {
        cout<<"Destructor is called"<<endl;
        Node* temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main()
{  
    LinkedList *newLinkedList = new LinkedList(54);

    delete newLinkedList;

    return 0;
}