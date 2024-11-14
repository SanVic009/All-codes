#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Graph{
private:
    unordered_map<string, unordered_set<string>> adjList;
public:
    void printGraph(){
        auto kvPair = adjList.begin();
        while (kvPair != adjList.end())
        {
            cout<<kvPair->first<<": [";
            // unordered_set<string>:: iterator
            auto edge = kvPair->second.begin();
            while(edge != kvPair->second.end())
            {
                cout<<edge->data()<<" ";
                edge++;
            }
            cout<<" ]"<<endl;
            kvPair++;
        }
    }

    bool addVertex(string vertex){
        if(adjList.count(vertex) == 0){
            adjList[vertex];
            return true;
        }
        return false;
    }
};

int main(){
    Graph *myGraph = new Graph();

    cout<<myGraph->addVertex("B")<<endl;
    cout<<myGraph->addVertex("B")<<endl;
    cout<<myGraph->addVertex("A")<<endl;

    myGraph->printGraph();
    return 0;
}