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
};

int main()
{

    LL *newLL = new LL(54);

    return 0;
}