
// created: 2023-05-26 23:34:44
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
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

bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y) return true;
	if(sz[x] < sz[y]) swap(x,y);
	sz[x] += sz[y];
	par[y] = x;
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = false;
		cin >> V >> E;
		make_set();
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			if(Union(u,v)) flag = true;
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';

	}

	return 0;
}
