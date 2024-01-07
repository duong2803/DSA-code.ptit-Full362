
// created: 2023-05-26 23:32:26
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int V, E, S, T;
int color[mxN];

bool dfs(int u){
	
	color[u] = 1;	
	for(int v : adj[u]){
		if(color[v] == 0){
			dfs(v);
		}
		else if(color[u] == 1) return true;
	}
	color[u] = 2;
	return false;
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
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}	
		bool flag= false;
		for(int i = 1; i <= V; ++i){
			memset(color, 0, sizeof(color));
			if(dfs(i))
				flag = true;
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}	
	return 0;
}

