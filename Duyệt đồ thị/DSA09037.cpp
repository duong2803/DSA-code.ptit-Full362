
// created: 2023-05-26 23:36:02
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
vector<int> a;
int k, n, m;
unordered_map<int,int> cnt;

void dfs(int u){
	visited[u] = true;
	cnt[u]++;
	for(int v: adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> k >> n >> m;

	a.resize(k);
	for(int i = 0; i < k; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}

	for(int i = 0; i < k; ++i){
		memset(visited, false, sizeof(visited));
		dfs(a[i]);
	}
	int res = 0;
	for(auto p: cnt){
		if(p.second == k){
			++res;
		}
	}
	cout << res;
	return 0;
}

