#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[100001];
void setDistance(int distance[100001]) {
    for(int i=0; i<100001; i++) {
        distance[i] = INT_MAX;
    }
}
void addEdges(int vertice, int neighbor, int weight) {
    graph[vertice].push_back({neighbor, weight});
    graph[neighbor].push_back({vertice, weight});
}
void shortestPath(int source, vector<bool> visited, int distance[100001]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        if(!visited[current]) {
            visited[current] = true;
            for(unsigned long i=0; i<graph[current].size(); i++) {
                int neighbor = graph[current][i].first;
                int weight = graph[current][i].second;
                if(distance[current] + weight < distance[neighbor]) {
                    distance[neighbor] = distance[current] + weight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
    }
} 
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int start, end;
    cin >> start >> end;
    vector<bool> visited(nodes+1, false);
    for(int i=0; i<edges; i++) {
        int vertice, neighbor, weight;
        cin >> vertice >> neighbor >> weight;
        addEdges(vertice, neighbor, weight);
    }
    int distance[100001];
    setDistance(distance);
    shortestPath(start, visited, distance);
    cout << distance[end];
}