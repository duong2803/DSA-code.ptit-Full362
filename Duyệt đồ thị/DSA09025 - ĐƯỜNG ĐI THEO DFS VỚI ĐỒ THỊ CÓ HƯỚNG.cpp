
// created: 2023-05-26 23:28:30
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
bool visited[mxN];
int par[mxN];
int V, E, U, D;
void dfs(int u = U){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			par[v] = u;
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
		cout << fr << ' ';
		for(int v: adj[fr]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

void solve(){
	dfs();
	if(!visited[D]){
		cout << -1;
		return;
	}	
	vector<int> path;
	while(D != U){
		path.push_back(D);
		D = par[D];
	}
	path.push_back(D);
	for(int i = path.size() - 1; i >= 0; --i){
		cout << path[i] << ' ';
	}
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
		cin >> V >> E >> U >> D;
			
		int a, b;
		for(int i = 0; i < E; ++i){
			cin >> a >> b;
			adj[a].push_back(b);
		}
		solve();
		cout << '\n';

	
	}
	return 0;
}

