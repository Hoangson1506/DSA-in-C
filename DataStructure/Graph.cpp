Trình
#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool dfs(vector<vector<int>> table, queue<int> q, vector<int> indegree, int m){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto i : table[x]){
			indegree[i]--;
			if(indegree[i] == 0){
				q.push(i);
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(indegree[i] != 0){
			return false;
		}
	}
	return true;
}

int main(){
	int m, n;
	cin>>m>>n;
	vector<vector<int>> table(m, vector<int>());
	vector<int> indegree(m, 0);
	queue<int> q;
	
	for(int i = 0; i < n; i++){
		int a, b;
		cin>>a>>b;
		table[a].push_back(b);
		indegree[b]++;
	}
	for(int i = 0; i < m; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	if(dfs(table, q, indegree, m)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
}