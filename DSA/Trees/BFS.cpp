#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *right;
    Node *left;

    Node(int value)
    {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree()
    {
        // Node *newNode = new Node (value);
        root = nullptr;
    }

    void BFS(){ 
        queue<Node*>myQueue;
        myQueue.push(root);

        while(myQueue.size()>0){
            Node *currentNode = myQueue.front();
            myQueue.pop();
            cout<<currentNode->value<<"\t";
            if(currentNode->left)
                myQueue.push(currentNode->left);
            if(currentNode->right)
                myQueue.push(currentNode->right);
        }
    }

    bool insert(int value)
    {
        Node *newNode = new Node(value);
        Node *temp = root;
        
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        while (true)
        {
            if (value == temp->value) return false;

            if (value > temp->value)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
        }
    }
};

int main()
{
    BinarySearchTree *myTree = new BinarySearchTree();
    myTree->insert(47);
    myTree->insert(21);
    myTree->insert(76);
    myTree->insert(18);
    myTree->insert(27);
    myTree->insert(52);
    myTree->insert(82);

    myTree->BFS();
    return 0;
}
