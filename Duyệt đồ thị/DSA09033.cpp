
// created: 2023-05-26 23:34:28
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
const ll mod = 1e9 + 7;
const int mxN = 100001;
vector<int> adj[mxN];
bool visited[mxN];
int V, E, S, T;
int par[mxN];

void dfs(int u = 1){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){
	bool flag = true;
	dfs();
	for(int i = 1; i <= V; ++i){
		if(!visited[i])
			flag = false;
	}
	cout << (flag ? "YES" : "NO") << '\n';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		solve();
	}	
	return 0;
}

