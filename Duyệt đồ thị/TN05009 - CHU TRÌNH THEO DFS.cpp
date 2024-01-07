
// created: 2023-05-26 23:35:08
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
int V, E;
bool flag;
int color[mxN];

void dfs(int u = 1, int p = 0, vector<int> cycle = {1}){
		
	color[u] = 1;
	for(int v: adj[u]){
		if(flag) return;
		if(color[v] == 0){
			cycle.push_back(v);
			dfs(v, u, cycle);
			cycle.pop_back();
		}else if(color[v] == 1 && v != p){
			if(v == 1){
				flag = true;
				for(int i : cycle){
					cout << i << ' ';
				}
				cout << 1;
			}
		}
	}

	color[u] = 2;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = false;
		memset(color, 0, sizeof(color));
		memset(adj, {}, sizeof(adj));
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 1; i <= V; ++i){
			sort(adj[i].begin(), adj[i].end());
		}		
		dfs();
		if(!flag)
			cout << "NO";
		cout << '\n';
	}

	return 0;
}

