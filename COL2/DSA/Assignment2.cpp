#include <bits/stdc++.h>
#define MAX 100

using namespace std;



class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};



class Queue
{
    Node* front;
    Node* rear;
    int length;

public:
    void insert(int val){
        Node* newnode = new Node(val);
        if (length == 0){
            front = newnode;
            rear = newnode;
        } else{
            newnode->next = rear;
            rear = newnode;
        }
        length++;
    }
    int dequeue(){
        if (length == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        front = front->next;
        int val = temp->value;
        delete temp;
        length--;
        return val;
    }

    int is_empty(){
        if(front == rear || rear == nullptr || front == nullptr){
            return 1;
        }
        else
            return 0;
    }
};



class Stack
{
private:
    Node *top;
    int height = 0;

public:
    int is_empty()
    {
        if (top == nullptr)
            return 1;
        else
            return 0;
    }

    void push(int val)
    {
        Node *temp = new Node(val);

        if (top == nullptr)
        {
            top = temp;
            height++;
            return;
        }
        temp->next = top;
        top = temp;
        height++;
    }

    int pop()
    {
        if (!is_empty())
        {
            Node *temp = top;
            top = temp->next;
            height--;
            return temp->value;
        }
        return -1;
    }
};



class Users
{
private:
    string name;
    int id;
    vector<int> friends;

public:
    friend class Graph;
};



class Graph
{
private:
    vector<Users> users;
    int id_counter = 0;
    int visited[MAX];

public:
    Graph(int n)
    {
        for (int i = 0; i < n; i++)
        {
            add_user();
        }

    }

    void add_user();
    void add_friends(int id);
    void print_graph();
    void nr_dfs(int id);
    void r_dfs(int id);
    void dfs();
    void bfs();
};

void Graph::add_user()
{

    if (id_counter == MAX)
    {
        cout << "Max limuser reached" << endl;
        return;
    }
    Users temp;
    cout << "Enter the name of the student: " << endl;
    cin >> temp.name;
    temp.id = id_counter;
    cout << "The id of " << temp.name << " is " << id_counter << endl;
    id_counter++;
    users.push_back(temp);
}

void Graph::add_friends(int id)
{
    int n = 0;
    cout << "Enter the number of friends you want to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int f_id = 0;
        cout << "Enter the id of friend " << i + 1 << ": ";
        cin >> f_id;
        if (f_id == id)
        {
            cout << "ID is invalid." << endl;
            i--;
            continue;
        }
        users[id].friends.push_back(f_id);
    }
}

void Graph::print_graph()
{
    cout << "Printing the adjacency list..." << endl;
    for (const auto &user : users)
    {
        cout << user.id << " " << user.name << " : ";

        for (const auto &f_id : user.friends)
        {
            cout << f_id << " <- ";
        }
        cout << "NULL" << endl;
    }
}

void Graph ::nr_dfs(int id)
{
    Stack stk;
    stk.push(id);

    while (!stk.is_empty())
    {
        int v = stk.pop();

        if (!visited[v])
        {
            cout << v << " : " << users[v].name << endl;
            visited[v] = 1;
        }

        for (auto f_id : users)
        {
            if (!visited[f_id.id])
            {
                stk.push(f_id.id);
            }
        }
    }
}

void Graph::dfs()
{

    int start_id = -1;
    cout << "Enter the starting id:";
    cin >> start_id;

    r_dfs(start_id);
}

void Graph::r_dfs(int id)
{
    visited[id] = 1;
    cout << id << " : " << users[id].name << endl;
    for (auto f_id : users)
    {
        if (!visited[f_id.id])
            r_dfs(f_id.id);
    }
}

void Graph:: bfs(){
    
    for(int i = 0; i < id_counter; i ++){
        visited[i] = 0;
    }

    int starting_id = -1;
    cout<<"Enter the starting id"<<endl;
    cin>>starting_id;

    Queue q;
    q.insert(starting_id);
    visited[starting_id] = 1;

    while( !q.is_empty()){

        int v= q.dequeue();

        cout<<users[v].id << " : "<< users[v].name<<endl;

        for(auto f_id : users){
            if(!visited[f_id.id]){
                q.insert(f_id.id);
                visited[f_id.id] = 1;
            }
        }
    }
}



int main()

{

    int n = 0;
    cout << "Enter the number of users you want to insert intially: ";
    cin >> n;
    Graph graph(n);

    // graph.print_graph();
    // graph.add_friends(0);
    // graph.add_friends(1);
    // graph.print_graph();
    // graph.nr_dfs(0);
    // graph.dfs();

    int choice = -1;
    do{
        cout << "\n----- Friend Network Menu -----\n";
        cout << "1. Add User\n";
        cout << "2. Add Friendship\n";
        cout << "3. Display Friend Network\n";
        cout << "4. Recursive DFS(Using ID)\n";
        cout << "5. Non-Recursive DFS(Using ID)\n";
        cout << "6. BFS(Using ID)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter user name: ";
            cin >> name;
            graph.add_user();
            break;
        }
        case 2:
        {
            cout<<"Enter the user for which you want to insert friends: "<<endl;
            int u_id = -1;
            cin>>u_id;
            graph.add_friends(u_id);
            break;
        }
        case 3:
            graph.print_graph();
            break;

        case 4:
            graph.dfs();
            break;

        case 5:
            cout<<"Enter the starting node: "<<endl;
            int starting_id = -1;
            cin>>starting_id;
            graph.nr_dfs(starting_id);
            break;

        case 6:
            graph.bfs();
            break;

        case 7:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}