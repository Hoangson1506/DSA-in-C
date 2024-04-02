#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v) {
    graph[u].push_back(v);
}
void countIndegree(vector<vector<int>> &graph, vector<int> &indegree, int V) {
    for(int i=1; i<=V; ++i) {
        for(auto adj : graph[i]) {
            indegree[adj]++;
        }
    }
}
vector<int> topologicalSort(vector<vector<int>> &graph, int V) {
    vector<int> indegree(V+1, 0);
    countIndegree(graph, indegree, V);
    queue<int> q;
    for(int i=1; i<=V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for(auto adj : graph[u]) {
            indegree[adj]--;
            if(indegree[adj] == 0) {
                q.push(adj);
            }
        }
    }
    if(result.size() < V) {
        cout << -1;
        return {};
    }
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    vector<int> result = topologicalSort(graph, n);
    for(int i=0; i<n; i++) {
        cout << result[i] << " ";
    }
}