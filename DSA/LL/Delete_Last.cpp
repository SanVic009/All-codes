#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

// more than  2 nodes
// no nodes
// only one node

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

    void deleteNode(void)
    {
        cout << "delete function has been called." << endl;
        if (length == 0)
        {
            cout << "This list has no nodes to remove." << endl;
        }
        else if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
            length--;
        }
    }
        // ALT CODE:
    void deleteLast2(void)
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }
    
};

int main()
{
    LL *myList = new LL(34);
    myList->append(54);
    myList->append(4);

    myList->printList();

    myList->deleteNode();
    myList->printList();

    LL *noList = new LL(45);

    noList->printList();

    noList->deleteNode();
    noList->printList();

    noList->deleteNode();
    noList->printList();

    // LL* qList = new LL (nullptr);

    return 0;
}