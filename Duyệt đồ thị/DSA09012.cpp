
// created: 2023-05-26 23:31:58
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int V, E, S, T;
int par[mxN];
int mat[mxN][mxN];
int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v])
			dfs(v);
	}
}

void solve(){
	
	for(int i = 1; i <= V; ++i){
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		for(int j = 1; j <= V; ++j){
			if(!visited[j]){
				dfs(j);
				++cnt;
			}
		}
		if(cnt >= 2){
			cout << i << ' ';
		}	
	}
	cout << '\n';
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

