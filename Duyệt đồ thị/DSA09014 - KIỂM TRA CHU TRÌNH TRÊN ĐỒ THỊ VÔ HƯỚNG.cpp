
// created: 2023-05-26 23:32:15
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
int V, E;
bool flag;
bool visited[mxN];

bool dfs(int u, int p = 0){
	visited[u] = true;
	for(int v: adj[u]){
		if(!visited[v]){
			if(dfs(v, u)) return true;
		}else if(v != p) return true;
	}
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = false;
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool flag = false;
		for(int i = 1; i <= V; ++i){
			if(!visited[i])
				if(dfs(i)) flag = true;
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	
	}

	return 0;
}

