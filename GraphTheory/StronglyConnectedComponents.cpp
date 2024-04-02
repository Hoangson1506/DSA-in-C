#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V; //number of vertices
    vector<vector<int>> graph; //representation of a graph
public:
    Graph(int V) {
        this->V = V;
        graph.resize(V);
    }
    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }
    void DFS(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for(auto adj : graph[v]) {
            if(!visited[adj]) {
                DFS(adj, visited);
            }
        }
    }
    Graph getTranspose() {
        Graph g(V);
        for(int v = 0; v < V; v++) {
            for(auto adj : graph[v]) {
                g.graph[adj].push_back(v);
            }
        }
        return g;
    }
    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack) {
        visited[v] = true;
        for(auto adj : graph[v]) {
            if(!visited[adj]) {
                fillOrder(adj, visited, Stack);
            }
        }
        Stack.push(v);
    } 
    void printSCCs() {
        vector<bool> visited(V, false);
        stack<int> Stack;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                fillOrder(i, visited, Stack);
            }
        }
        Graph transpose = getTranspose();
        visited.assign(V, false);
        while(!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            if(!visited[v]) {
                transpose.DFS(v, visited);
                cout << "\n";
            }
        }
    }   
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.printSCCs();

    return 0;
}