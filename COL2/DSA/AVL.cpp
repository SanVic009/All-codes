/*
write a a program to implement an avl tree for dictionary. A dictionary stores keywords anode its meaning. Provide facility for adding new keywords, updating meaning of any entry. provide a facility to display whole data sorted in ascending order. Also find how many maximum comparisons are require for finding any keyword. Use a height balanced tree and find the complexity for finding a keyword.
*/

#include<bits/stdc++.h>

using namespace std;

class avl_node{

private:
    string key;
    string meaning;
    avl_node* left;
    avl_node* right;

public:
    avl_node(){
        this->key = "";
        this->meaning = "";
        this->left = nullptr;
        this->right = nullptr;
    }

    friend class avl_tree;
};

class avl_tree{

private:
    avl_node* root;
    
public:
    void insert(string key, string meaning);
    avl_node* insert(avl_node* node, string key, string meaning);
    int height(avl_node* node);
    int bal_factor(avl_node* node);
    avl_node* balance (avl_node* node);

    avl_node* ll(avl_node* parent);
    avl_node* rr(avl_node* parent);
    avl_node* lr(avl_node* parent);
    avl_node* rl(avl_node* parent);

    void display_tree(avl_node* ptr, int level);
    void inorder(avl_node* node);
    void preorder(avl_node* node);
    void postorder(avl_node* node);
};

void avl_tree::insert(string key, string meaning) {
    root = insert(root, key, meaning);
}

avl_node* avl_tree::insert(avl_node* node, string key, string meaning) {
    if (node == nullptr) {
        node = new avl_node();
        node->key = key;
        node->meaning = meaning;
        return node;
    }

    if (key < node->key) {
        node->left = insert(node->left, key, meaning);
    } else if (key > node->key) {
        node->right = insert(node->right, key, meaning);
    } else {
        return node;
    }

    return balance(node);
}

int avl_tree::height(avl_node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

int avl_tree::bal_factor(avl_node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

avl_node* avl_tree::balance(avl_node* node) {

    int balance_factor = bal_factor(node);
    if (balance_factor > 1 && bal_factor(node->left) >= 0) {
        return ll(node);
    }
    if (balance_factor > 1 && bal_factor(node->left) < 0) {
        return lr(node);
    }

    if (balance_factor < -1 && bal_factor(node->right) <= 0) {
        return rr(node);
    }
    if (balance_factor < -1 && bal_factor(node->right) > 0) {
        return rl(node);
    }

    return node;
}

void avl_tree::display_tree(avl_node* ptr, int level){
    if(ptr!= nullptr){
        display_tree(ptr->right, level+1);
        cout<<endl;
        if(ptr == root)
            cout<<"Root->";
        for(int i = 0; i < level && ptr!= root; i++){
            cout<<" ";
        }
        cout<<ptr->key;
        display_tree(ptr->left, level+1);
    }
}

avl_node* avl_tree::ll(avl_node* parent){

    avl_node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node* avl_tree::rr(avl_node* parent){

    avl_node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node* avl_tree::lr(avl_node* parent){

    avl_node* temp = parent->left;
    parent->left = rr(temp);
    return ll(parent);
}

avl_node* avl_tree::rl(avl_node* parent){

    avl_node* temp = parent->right;
    parent->right = ll(temp);
    return rr(parent);
}

int main(){

    return 0;

}