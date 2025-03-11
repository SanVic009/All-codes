// Write a program to implement AVL tree for Dictionary. A Dictionary stores keywords & its meaning. provide facility for adding new keywords, updating meaning of any entry. provide a facility to display whole data sorted in ascending order. also find how many maximum comparisons may require for finding any keyword. Use height balanced tree and find the complexity for finding a keyword.

#include<iostream>
#include<string>
using namespace std;

class node{
    string keyword;
    string meaning;
    node *left;
    node *right;

    public:
    friend class avl_tree;
};

class avl_tree{
    node *root;
    public:
    avl_tree(){
        root = NULL;
    }

    int height(node *temp);
    int balance_factor(node *temp);
    node* rr_rotation(node *root);
    node* ll_rotation(node *root);  
    node* lr_rotation(node *root);
    node* rl_rotation(node *root);
    void insert(string key, string mean);
    node *balance(node *temp);
    node* insert(node *root, string key, string mean);
    void display(node *temp);
    void inorder(node *temp);
    void preorder(node *temp);
    void postorder(node *temp);
    node* get_root();
};

node* avl_tree::get_root(){
    return root;
}

int avl_tree::height(node *temp){
    int h = 0;
    if(temp != NULL){
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int avl_tree::balance_factor(node *temp){
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int balance_factor = l_height - r_height;
    return balance_factor;
}

node* avl_tree::insert(node *root, string key, string mean){
    if(root == NULL){
        root = new node;
        root->keyword = key;
        root->meaning = mean;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else if(key < root->keyword){
        root->left = insert(root->left, key, mean);
        root = balance(root);
    } else if(key >= root->keyword){
        root->right = insert(root->right, key, mean);
        root = balance(root);
    }
    return root;
}

void avl_tree::insert(string key, string mean){
    root = insert(root, key, mean);
}

node* avl_tree::balance(node *temp){
    int bal_factor = balance_factor(temp);
    if(bal_factor > 1){
        if(balance_factor(temp->left) > 0){
            temp = ll_rotation(temp);
        } else {
            temp = lr_rotation(temp);
        }
    } else if(bal_factor < -1){
        if(balance_factor(temp->right) > 0){
            temp = rl_rotation(temp);
        } else {
            temp = rr_rotation(temp);
        }
    }
    return temp;
}

node* avl_tree::rr_rotation(node *root){
    cout<<"Doing RR rotation"<<endl; 
    node *temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node* avl_tree::ll_rotation(node *root){
    cout<<"Doing LL rotation"<<endl; 
    node *temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node* avl_tree::lr_rotation(node *root){
    cout<<"Doing LR rotation"<<endl; 
    node *temp;
    temp = root->left;
    root->left = rr_rotation(temp);
    return ll_rotation(root);
}

node* avl_tree::rl_rotation(node *root){
    cout<<"Doing RL rotation"<<endl;
    node *temp;
    temp = root->right;
    root->right = ll_rotation(temp);
    return rr_rotation(root);
}


void avl_tree::display(node *temp){
    if(root == NULL){
        cout << "Tree is empty" << endl;
    } else {
        cout << "Inorder: ";
        inorder(temp);
        cout << endl;
        cout << "Preorder: ";
        preorder(temp);
        cout << endl;
        cout << "Postorder: ";
        postorder(temp);
        cout << endl;
    }
}

void avl_tree::inorder(node *temp){
    if(temp != NULL){
        inorder(temp->left);
        cout << temp->keyword << " ";
        inorder(temp->right);
    }
}   

void avl_tree::preorder(node *temp){
    if(temp != NULL){
        cout << temp->keyword << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void avl_tree::postorder(node *temp){
    if(temp != NULL){
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->keyword << " ";
    }
}

int main(){
    avl_tree avl;
    int choice;
    string key, mean;
    while(1){
        cout << "1. Add the word" << endl;
        cout << "2. Display the AVL tree" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Insert the keyword: ";
                cin>>key;
                cout<<"Insert meaning: ";
                cin>>mean;
                avl.insert(key, mean);
                break;
            case 2:
                avl.display(avl.get_root());
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}