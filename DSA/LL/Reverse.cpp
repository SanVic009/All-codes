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
    Node *head;
    Node *tail;
    int length;

public:
    LL(int value)
    {
        Node *nNode = new Node(value);
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
        length++;
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

        // Node *sig = nullptr;
    void reverseList(void)
    {
        Node *temp = head;
        Node *pre = temp->next;
        Node *sig = pre->next;

        head = tail;
        tail = temp;

        temp->next = nullptr;
        // sequence is :
        // temp->pre->sig
        for (int i = 0; i < length; i++)
        {
            pre = temp->next;
            temp->next = sig;
            sig = temp;
            temp = pre;
        }
        // while (temp == head)
        // {
        //     pre->next= temp;
        //     temp = pre; 
        //     pre = sig;
        //     sig = sig->next;
        // }

    }
};

int main()
{
    LL* node = new LL (34);
    node->append(54);
    node->append(12);
    node->append(76);
    node->printList();

    node->reverseList();
    cout<<"Reversing the list."<<endl;

    node->printList();
    
    return 0;
}