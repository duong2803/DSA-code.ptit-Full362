
// created: 2023-05-26 23:36:19
// author: Nguyen Tung Duong


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 200001;
vector<int> adj[mxN];
vector<ll> d(mxN);
vector<ll> c(mxN);
int n;

void dfs(int u = 1){
	for(int v: adj[u]){
		dfs(v);
		c[u] += c[v];
		d[u] += d[v] + c[v];
	}
	d[u]++;
	c[u]++;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 2; i <= n; ++i){
		int x;
		cin >> x;
		adj[x].push_back(i);	
	}
	dfs();
	for(int i = 1; i <= n; ++i){
		cout << d[i] << ' ';
	}
	return 0;
}

