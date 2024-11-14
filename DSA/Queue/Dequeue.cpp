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
    
    void dequeue(){
        if(length == 0)
            return ;
        if(length == 1){
            delete first;
            first = nullptr;
            last = nullptr;
        }else {
            Node *temp = first;
            first = first->next;
            delete temp;
        }
        length++;
    }

    void enqueue(int value){
        Node *temp = new Node (value);
        if(length == 0){
            first = temp;
            last = temp;
        }else {
            last->next = temp;
            last = temp;
        }
        length ++;
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