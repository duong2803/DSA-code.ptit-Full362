
// created: 2023-05-26 23:28:55
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int par[mxN];
int V, E, U, D;
void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}	
}

void bfs(){
	queue<int> q;
	q.push(U);
	visited[U] = true;
	while(!q.empty()){
		int fr = q.front(); q.pop();
		for(int v: adj[fr]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

void solve(){
	memset(visited,false, sizeof(visited));
	dfs(U);
	if(visited[D]){
		cout << "YES";
	}else
	    cout << "NO";
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
		memset(par, 0, sizeof(par));
		cin >> V >> E;
		int a,b;
		for(int i = 0; i < E; ++i){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int q;
		cin >> q;
		while(q--){
		    memset(visited, false, sizeof(visited));
			cin >> U >> D;
			solve();
			cout << '\n';
		}
	
	}
	return 0;
}
