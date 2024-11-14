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

    void DFSPreOrder(){DFSPreOrder(root);}

    void DFSPreOrder(Node *currentNode){
        cout<<currentNode->value<<"\t";
        if(currentNode->left)
            DFSPreOrder(currentNode->left);
        if(currentNode->right)
            DFSPreOrder(currentNode->right);
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

    myTree->DFSPreOrder();

    return 0;
}