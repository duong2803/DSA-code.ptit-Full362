
// created: 2023-05-26 23:48:40
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[1001];
int anc[mxN][19];
int d[mxN];
int n;


void dfs(int u = 1){
	for(int v: adj[u]){
		if(v == anc[u][0]) continue;
		d[v] = d[u] + 1;

		anc[v][0] = u;

		for(int i = 1; i < 19; ++i)
			anc[v][i] = anc[anc[v][i - 1]][i - 1];
		dfs(v);
	}
}
int lca(int u, int v){
	int dist = 0;
	if(d[u] < d[v]) swap(u, v);
	for(int i = 18; ~i; --i)
		if((1 << i) <= d[u] - d[v]){
			u = anc[u][i];
			dist += (1 << i);
		}
	if(u == v) return dist;
	for(int i = 18; ~i; --i)
		if(anc[u][i] ^ anc[v][i]){
			u = anc[u][i], v = anc[v][i];
			dist += (1 << i + 1);
		}
	return dist + 2;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(adj, {}, sizeof(adj));
		memset(d, 0, sizeof(d));
		cin >> n;
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		dfs();
		int q;
		cin >> q;

		while(q--){
			int u, v;
			cin >> u >> v;
			cout << lca(u,v) << '\n';
		}
	}

	return 0;
}

