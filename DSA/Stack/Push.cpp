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

class Stack{
private:
    Node *top;
    int height;

public:
    Stack (int value){
        Node *newNode = new Node (value);
        top = newNode;
        height = 1;
    }

    int getTop(){
        int toper = top->value;
        return toper;
    }

    int getHeight(){
        int h = height;
        return h;
    }

    void printStack(){

        Node *temp = top;
        for(int i = 0; i <height ; i++){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }
    
    void push (int value){
        Node *newNode = new Node (value);
        newNode->next = top;
        top =newNode;
        height++;
    }

};

int main(){
    Stack *myStack = new Stack (5);

    // cout<<"Height  is: "<<myStack->getHeight()<<endl;
    // cout<<"Top : "<<myStack->getTop()<<endl;
    myStack->printStack();
    myStack->push(3 );
    myStack->printStack();

    return 0;
}