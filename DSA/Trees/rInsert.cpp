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


    bool rContain(Node *currentNode , int value){
        if(currentNode == nullptr) return false;

        if(currentNode->value == value) return true;
        if(currentNode->value < value)
            return rContain(currentNode->right, value);
        else
            return rContain(currentNode->left, value);
    }

    bool rContain(int value){
        return rContain(root, value);
    }

    Node *rInsert(Node *currentNode , int value){
        if(currentNode == nullptr) return new Node(value);
        if(value< currentNode->value){
            currentNode->left = rInsert(currentNode->left, value);
        } else if (value> currentNode->value)
            currentNode->right = rInsert(currentNode->right, value);
        return currentNode;
    }

    void rInsert(int value){
        if(root == nullptr) root = new Node (value);
        rInsert(root, value);
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

    cout<<"\nBST contains 27: ";
    if(myTree->rContain(27)? cout<<"YES": cout<<"NO")

    cout<<"\nBST contains 17: ";
    if(myTree->rContain(17)? cout<<"YES": cout<<"NO")
    return 0;
}