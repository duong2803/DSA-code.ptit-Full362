
// created: 2023-05-26 23:37:18
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int V, E, S, T;

bool bfs(int U){
	
	queue<int> q;
	int par[mxN];
	q.push(U);
	visited[U] = true;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v: adj[u]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
				par[v] = u;
			}else if(v != par[u]){
				return true;
			}
		}
	}
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
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}	
		bool flag = false;	
		for(int i = 1; i <= V; ++i){
			memset(visited, false, sizeof(visited));
				if(bfs(i)) flag = true;
			
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}	
	return 0;
}

