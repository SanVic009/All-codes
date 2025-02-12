#include<bits/stdc++.h>

#define MAX 100

using namespace std;



class Business{
private:
    int business_id;
    string business_name;
    Neighbour nb;
public:
    friend class Graph;
};



class Neighbour {
private:
    int visited = 0;
    int cost =0;
    int prev;

public:
    friend class Graph;
};



class Graph{
private:
    int office_counter = 0;
    vector<vector<int>> adjacency_mat;
    vector<Business> businesses;
    vector<Neighbour> nb;

public:
    void add_office();
    void add_cost();
    void display_graph();
    void prim(int starting_id);
    int all_visited();
};

void Graph::prim(int starting_id){
    
    int size = businesses.size() - 1;
    nb[starting_id].visited = 1;
    nb[starting_id].cost = 0;
    nb[starting_id].prev = -1;

    for(int i = 0; i < businesses.size(); i++){
        if(!all_visited()){
            
        }
    }
}

int Graph::all_visited(){
    for(auto neighbours : nb){
        if(neighbours.visited == 0){
            return 0;
        }
    }
}

void Graph::display_graph(){

    for (int i = 0; i < businesses.size(); i++){
        cout<<"\\\t"<<businesses[i].business_id<<"\t"<<endl;
    }

    for(int i = 0; i < businesses.size(); i++){
        cout<<businesses[i].business_id<<"\t";
        for(int j = i; j < businesses.size(); j++){
            cout<<adjacency_mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void Graph::add_cost(){
    int choice = 1;
    while(choice){
        int b1,weight, b2;
        cout<<"Enter the id of the first business: ";
        cin>>b1;
        cout<<"Enter the id of the second business: ";
        cin>>b2;
        cout<<"Enter the rent of the cable between them: ";
        cin>>weight;

        adjacency_mat[b1][b2] = weight;
        adjacency_mat[b2][b1] = weight;
    }
}

void Graph::add_office(){
    Business temp;

    cout<<"Enter the name of the business: ";
    cin>>temp.business_name;
    temp.business_id = office_counter;
    office_counter++;
    cout<<"The id of "<<temp.business_name<<" is "<<temp.business_id<<endl;

    businesses.push_back(temp);

    for(int i = 0; i < businesses.size(); i++){
        adjacency_mat[temp.business_id][i] = INT_MIN;
    }    
}    

int main(){

    return 0;
}