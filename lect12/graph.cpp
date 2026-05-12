// graph.cpp
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
class Graph{
    public:
        Graph(int n){
            adjlist.resize(n);
        }
        void addEdge(int source, int dest){
            adjlist[source].insert(dest);  // Directed graph
        }
        void display(){
            for(int u = 0; u < adjlist.size(); u++ ){
                cout << u << " : ";
                for (auto v : adjlist[u]){
                    cout << v << ", ";
                }
                cout << endl;
            }
        }
    
    private:
        vector<unordered_set<int>> adjlist;
};

/*
Unweighted graph
Edge List E = {  (0, 2), 
                 (2, 3), (2, 1), (2, 4), 
                 (3, 1),  
                 (1, 5), (1, 4),
                 (4, 5)
                 }

Write the Adjacency list representation for the example graph

adjlist = { {2},
            {4, 5},
            {3, 1, 4},
            {1},
            {5},
            {}
}


Weighted graph
Edge List E = {  (0, 2, 0.5), 
                 (2, 3, 0.1), (2, 1, 0.7), (2, 4, 0.2), 
                 (3, 1, 0.3),  
                 (1, 5, 0.1), (1, 4, 0.9),
                 (4, 5, 0.3)
                 }
*/
int main(int argc, char const *argv[])
{
    Graph g(6); 
    g.addEdge(0, 2); 
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(4, 5);

    g.display();
    return 0;
}
