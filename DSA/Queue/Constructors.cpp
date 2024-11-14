#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node (int value){
        this->value = value;
        next = nullptr;
    }
};

class Queue{
private:
    Node *first;
    Node *last;
    int length;
public:
    Queue(int value){
        Node *newNode = new Node (value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    void printQueue(){
        Node *temp = first;
        while (length --){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }
};

int main(){
    
    return 0;
}