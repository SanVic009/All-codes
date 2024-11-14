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

    void DFSPostOrder(){DFSPostOrder(root);}

    void DFSPostOrder(Node *currentNode){
        if(currentNode->left)
            DFSPostOrder(currentNode->left);
        // cout<<currentNode->value<<"\t";
        if(currentNode->right)
            DFSPostOrder(currentNode->right);
        cout<<currentNode->value<<"\t";
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
    // myTree->insert(17);
    // myTree->insert(19);
    // myTree->insert(26);
    // myTree->insert(28);
    // myTree->insert(51);
    // myTree->insert(53);
    // myTree->insert(81);
    // myTree->insert(83);

    myTree->DFSPostOrder();

    return 0;
}