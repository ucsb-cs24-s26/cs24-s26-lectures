// graph.cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph {
    public:
        Graph(int n) {
            adjlist.resize(n);
        }
        void addEdge(int source, int dest) {
            adjlist[source].insert(dest); 
            adjlist[dest].insert(source); 
        }
        void display() {
            for (int u = 0; u < adjlist.size(); u++) {
                cout << u << " : ";
                for (auto v : adjlist[u]) {
                    cout << v << ", ";
                }
                cout << endl;
            }
        }
        void exploreBFS(int source) {
            // TODO: implement BFS traversal starting from source
            queue<int> q;
            int n = adjlist.size();
            vector<bool> visited(n, false);
            visited[source] = true;
            cout << source << " ";
            q.push(source);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : adjlist[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        cout << v << " ";
                        q.push(v);
                    }
                }
            }
        }

    private:
        vector<unordered_set<int>> adjlist;
};

/*
(Set of vertices) V = {0, 1, 2, 3, 4, 5}
Edge List E = {  (0, 2),
                 (2, 3), (2, 1), (2, 4),
                 (3, 1),
                 (1, 5), (1, 4),
                 (4, 5)
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
    cout << "Breadth First Traversal" <<endl;
    g.exploreBFS(0);
    cout << endl;
    return 0;
}
