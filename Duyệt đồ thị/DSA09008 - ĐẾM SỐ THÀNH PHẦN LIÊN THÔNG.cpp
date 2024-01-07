
// created: 2023-05-26 23:30:03
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
const ll mod = 1e9 + 7;
const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int V, E, S, T;
int par[mxN];

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){
	int cnt = 0;
	for(int i = 1; i <= V; ++i){
		if(!visited[i]){
			dfs(i);
			++cnt;
		}
	}	
	cout << cnt << '\n';
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
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		solve();
	}	
	return 0;
}

