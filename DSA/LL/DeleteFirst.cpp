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

    void deleteFirst(void)
    {
        Node *temp = head;
        if (length == 0)
        {
            cout << "There are no elements in the linked list." << endl;
        }
        else if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            delete temp;
            length--;
        }
        else
        {
            head = head->next;
            delete temp;
            length--;
        }
        cout<<"End of the fucntion."<<endl;
    }
};

int main()
{
    LL *node = new LL(34);
    node->append(54);
    node->printList();

    node->deleteFirst();
    node->printList();
    node->deleteFirst();
    node->printList();
    node->deleteFirst();
    node->printList();
    return 0;
}