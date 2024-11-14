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

class LL
{
private:
    Node *head;
    Node *tail;
    int len;

public:
    LL(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        len = 1;
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

    void getHead(void){
        cout<<"The value of the head node is: "<<head->value<<endl;
    }

    void getTail(void){
        cout<<"The value of the tail node is: "<<tail->value<<endl;
    }

    void getLength(void){
        cout<<"The length of the linked list is: "<<len<<endl;
    }
};

int main()
{

    LL *newLL = new LL(54);

    newLL->getHead();
    newLL->getTail();
    newLL->getLength();

    newLL->printList();
    return 0;
}