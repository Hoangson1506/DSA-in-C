#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}
bool compareWeight(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.second <= b.second.second;
}
void primMST(vector<vector<pair<int, int>>> &graph) {
    int total = 0;
    int V = graph.size();
    int source = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V+1, INT_MAX);
    vector<int> parent(V+1, -1);
    vector<bool> inMST(V+1, false);
    key[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]) continue; 
        total += key[u]; 
        inMST[u] = true;
        for(auto adj : graph[u]) {
            int v = adj.first;
            int w = adj.second;
            if(!inMST[v] && key[v] > w) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    pair<int, pair<int, int>> result[V+1];
    for(int i=1; i<V; i++) {
        result[i] = {i, {parent[i], key[i]}};
    }
    sort(result+1, result+V, compareWeight);
    cout << total << "\n";
    for(int i=2; i<V; i++) {
        cout << result[i].first << " " << result[i].second.first << " " << result[i].second.second << "\n";
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }
    primMST(graph);
}