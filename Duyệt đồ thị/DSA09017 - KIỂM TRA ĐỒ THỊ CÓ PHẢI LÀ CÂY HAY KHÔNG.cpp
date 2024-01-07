
// created: 2023-05-26 23:32:49
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
int V, E, n;
bool flag;
bool visited[mxN];
int sz[mxN];
int par[mxN];

void make_set(){
	for(int i = 1; i <= n; ++i){
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
	if(x == y) return false;
	if(sz[x] < sz[y]) swap(x,y);
	sz[x] += y;
	par[y] = x;
	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = true;
		cin >> n;
		make_set();	
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			cin >> u >> v;
			if(!Union(u,v)) flag = false;
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}

