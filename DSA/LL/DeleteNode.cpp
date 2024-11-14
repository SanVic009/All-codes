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
        cout << "End of the fucntion." << endl;
    }

    void deleteLast(void)
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

    bool deleteNode(int index)
    {
        Node *pre = get(index - 1);
        Node *del = pre->next;
        if (index < 0 || index >= length)
        {
            cout << "Index out of bounds." << endl;
            return false;
        }
        if (index == 0)
        {
            deleteFirst();
            return true;
        }
        if (index == length - 1)
        {
            deleteLast();
            return true;
        }

        pre->next = del->next;
        delete del;

        length--;
        return true;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Index " << index << " is out of bounds." << endl;
            return nullptr;
        }
        Node *temp = head;
        int i = 0;
        for (; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
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
};

int main()
{

    LL *myList = new LL(0);
    myList->append(1);
    myList->append(2);

    myList->printList();

    cout << "First delete" << endl;
    myList->deleteNode(0);
    myList->printList();

    cout << "Second delete" << endl;
    myList->deleteNode(1);
    myList->printList();
    
    cout << "Third delete" << endl;
    myList->deleteNode(0);
    myList->printList();

    return 0;
}