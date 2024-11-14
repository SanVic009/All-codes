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

    bool contains(int value){
        if(root == nullptr) return false;

        Node *temp = new Node (value);
        while(temp){
            if(value == temp->value) return true;

            if(value >temp->value) temp = temp->right;
            else if(value <temp->value) temp = temp->left;
        }
        return false;
    }
};

int main()
{
    BinarySearchTree *myTree = new BinarySearchTree();

    return 0;
}