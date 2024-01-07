
// created: 2023-05-26 23:26:55
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int mxN = 1e3;
vector<int> adj[mxN];
bool visited[mxN];
int n, m;
int low[mxN];
int ids[mxN];
int id;
set<pair<int,int>> res;

void dfs(int u = 0, int p = -1){
	visited[u] = true;
	low[u] = ids[u] = id++;
	for(int v: adj[u]){
		if(v == p) continue;
		if(!visited[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		   	if(ids[u] < low[v]){
				int x = u, y = v;
				if(x > y) swap(x, y);
				res.insert({x,y});
			}
		}
		else
			low[u] = min(low[u], ids[v]);
	}
}

int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		res.clear();
		id = 0;
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			adj[i].clear();
			visited[i] = false;
			low[i] = ids[i] = -1;
		}
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v; --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs();
		for(auto i: res)
			cout << i.first + 1 << ' ' << i.second + 1<< ' ';
		cout << '\n';
	}	

	return 0;
}

