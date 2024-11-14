#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    void printGraph()
    {
        auto kvPair = adjList.begin();
        while (kvPair != adjList.end())
        {
            cout << kvPair->first << ": [";
            auto edge = kvPair->second.begin();
            while (edge != kvPair->second.end())
            {
                cout << edge->data() << ", ";
                edge++;
            }
            cout << " ]" << endl;
            kvPair++;
        }
    }

    bool addEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }

    bool addVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool removeEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
    // NOTE: use removeEdge funtion in future if you figure it out.
    // removeEdge(vertex, adjList.at(otherVertex));
    bool removeVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
            return false;

        for (auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

    int main()
    {
        Graph *myGraph = new Graph();

        cout << myGraph->addVertex("B") << endl;
        cout << myGraph->addVertex("B") << endl;
        cout << myGraph->addVertex("A") << endl;
        cout << myGraph->addVertex("C") << endl;
        cout << myGraph->addVertex("D") << endl;

        myGraph->printGraph();

        cout << myGraph->addEdge("A", "B") << endl;
        cout << myGraph->addEdge("C", "B") << endl;
        cout << myGraph->addEdge("A", "C") << endl;
        cout << myGraph->addEdge("A", "D") << endl;
        cout << myGraph->addEdge("B", "D") << endl;

        myGraph->printGraph();

        // cout << myGraph->removeEdge("A", "B") << endl;
        // cout << myGraph->removeEdge("A", "D") << endl;

        cout<<myGraph->removeVertex("A")<<endl;

        myGraph->printGraph();
        return 0;
    }