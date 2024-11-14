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
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL
{
private:
    int length;
    Node *head;
    Node *tail;

public:
    DLL(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
        return;
    }

    void deleteFirst(void){
        if(length == 0)
            return ;
        if(length == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
        }else {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length --;
        return;
    }

    void deleteLast(void)
    {
        if(length == 0)
            return ;
        if(length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length --;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length --;
        return;
    }

    void getHead()
    {
        if (head == nullptr)
        {
            cout << "Head: nullptr" << endl;
        }
        else
        {
            cout << "Head: " << head->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void getTail()
    {
        if (tail == nullptr)
        {
            cout << "Tail: nullptr" << endl;
        }
        else
        {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void prepend(int value){
        Node* temp = new Node(value);
        if(length == 0){
            head = temp;
            tail = temp;
        } else {
            temp->next = head->next;
            head->prev = temp;
            head = temp;
        }
        length ++;
        return;
    }

    void printList()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    DLL *myList = new DLL (2);
    myList->append(5);
    myList->append(6);
    // myList->printList();

    // myList->deleteLast();
    // myList->prepend(4);
    // myList->deleteFirst();

    myList->printList();
    return 0;
}
