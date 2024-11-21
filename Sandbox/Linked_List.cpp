#include <bits//stdc++.h>


class Node {
public:
    int data;
    Node *next;

    Node (){
        this->next = NULL;
    }
};

class ll{
    int length;
    Node head;

public:
    ll(int data){
        Node* newNode = new Node;
        head.next= newNode;
        newNode->data = data;
    }
};

int main(){
    ll* liset = new ll(23);
}