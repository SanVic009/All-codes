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
            if (value == temp->value)
                return false;

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

    bool rContain(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return false;

        if (currentNode->value == value)
            return true;
        if (currentNode->value < value)
            return rContain(currentNode->right, value);
        else
            return rContain(currentNode->left, value);
    }

    bool rContain(int value)
    {
        return rContain(root, value);
    }

    Node *rInsert(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return new Node(value);
        if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value)
            currentNode->right = rInsert(currentNode->right, value);
        return currentNode;
    }

    void rInsert(int value)
    {
        if (root == nullptr)
            root = new Node(value);
        rInsert(root, value);
    }

    Node *deleteNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return nullptr;
        if (value < currentNode->value)
            currentNode->left = deleteNode(currentNode->left, value);
        else if (value > currentNode->value)
            currentNode->right = deleteNode(currentNode->right, value);
        else
        {
            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                delete currentNode;
                return nullptr;
            }
            else if (currentNode->left == nullptr)
            {
                Node *temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else
            {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }
        return currentNode;
    }

    void deleteNode(int value){ root = deleteNode(root, value);}

    int minValue(Node *currentNode)
    {
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }
};

int main()
{
    BinarySearchTree *myTree = new BinarySearchTree();

    myTree->insert(3);
    myTree->insert(1);
    myTree->insert(2);
    

    
    return 0;
}