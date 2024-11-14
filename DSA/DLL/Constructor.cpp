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
    DLL (int value)
    {
        Node *newNode = new Node (value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    
    void printList()
    {
        Node *temp = head;

        while(temp)
        {
            cout<<temp->value<<endl;
            temp =  temp->next;
        }
        return;
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        } else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        } else { 
            cout << "Tail: " << tail->value << endl;
        }  
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }
};

int main()
{

    return 0;
}