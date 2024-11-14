#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

         Node* get(int index){
        if(index<0 || index >=length)
        {
            cout<<"Index "<<index<<" is out of bounds."<<endl;
            return nullptr;
        }
        Node * temp = head;
        int i = 0;
        for (; i < index; i++)
        {
            temp = temp->next;
        }
        cout<<"The value of index "<<i<<" is "<<temp->value<<endl;   
    }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Find the middle node of the linked list            |
        //   | - Return type: Node*                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - 'slow' moves one step, 'fast' moves two            |
        //   | - When 'fast' reaches the end, 'slow' is at middle   |
        //   | - Return 'slow' as the middle node                   |
        //   +======================================================+

        Node* findMiddleNode(void){
            // int middle = 0;
            // if(length %2 == 0)
            //     middle = length /2 +1;
            // else 
            //     middle = length /2;

            // // Node* temp = head;
            // // while (middle --){
                
            // // }
            // return get(middle);

            Node *slow = head;
            Node *fast = head;

            while(fast != tail || fast != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};