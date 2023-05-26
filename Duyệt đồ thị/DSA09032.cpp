
// created: 2023-05-26 23:34:16
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 100001;
vector<int> adj[mxN];
int V, E;
bool flag;
bool visited[mxN];
int sz[mxN];
int par[mxN];

void make_set(){
	for(int i = 1; i <= V; ++i){
		sz[i] = 1;
		par[i] = i;
	}
}

int Find(int u){
	if(u == par[u]) return u;
	return par[u] = Find(par[u]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x,y);
	sz[x] += sz[y];
	par[y] = x;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> V >> E;
		make_set();
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			Union(u,v);
		}
		int res = 1;
		for(int i = 1; i <= V; ++i){
			res = max(res, sz[i]);
		}
		cout << res << '\n';
	}

	return 0;
}

