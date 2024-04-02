#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w) {
    graph[u].push_back({v, w});
}
bool bellmanFord(vector<vector<pair<int, int>>> &graph, vector<int> &distance, int source, int V) {
    distance[source] = 0;
    for(int i=0; i<V-1; i++) {
        for(int u = 0; u < V; ++u) {
            for(const auto &edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                if(distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return false;
            }
        }
    }
    return true;
}
int main() {
    int V = 5; 
    int source = 0; 
    vector<vector<pair<int, int>>> graph(V);
    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    vector<int> distance(V, INT_MAX);

    if (bellmanFord(graph, distance, source, V)) {
        cout << "Distance from source vertex " << source << ":" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " -> " << distance[i] << endl;
        }
    }

    return 0; 
}