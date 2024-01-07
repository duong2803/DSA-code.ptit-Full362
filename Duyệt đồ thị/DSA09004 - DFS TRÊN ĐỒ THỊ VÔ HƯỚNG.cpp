
// created: 2023-05-26 23:26:32
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];

int V, E, U;
void dfs(int u = U){
	cout << u << ' ';
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}	
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cin >> V >> E >> U;
			
		int a, b;
		for(int i = 0; i < E; ++i){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs();
		cout << '\n';

	
	}
	return 0;
}

