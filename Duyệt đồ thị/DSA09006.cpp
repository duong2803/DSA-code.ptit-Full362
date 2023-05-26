
// created: 2023-05-26 23:29:39
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

void dfs(int u = S){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			par[v] = u;
			dfs(v);
		}
	}
}
void solve(){
	memset(par, 0, sizeof(par));
	dfs();
	if(!visited[T]){
		cout << -1 << '\n';
		return;
	}
	vector<int> path;
	while(S != T){
		path.push_back(T);
		T = par[T];
	}
	path.push_back(S);
	reverse(path.begin(), path.end());
	for(int i : path){
		cout << i << ' ';
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
		memset(visited, false, sizeof(visited));
		cin >> V >> E >> S >> T;
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

