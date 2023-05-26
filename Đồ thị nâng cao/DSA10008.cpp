
// created: 2023-05-26 23:38:13
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
const int INF = 1e9;
int V, E, U;
vector<pair<int,int>> adj[mxN];

void dijkstra(){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	vector<int> dist(V + 1, INF);
	dist[U] = 0;
	q.push({0, U});
	while(!q.empty()){
		pair<int,int> x = q.top(); q.pop();
		if(x.first > dist[x.second]) continue;
		for(pair<int,int> v: adj[x.second]){
			if(dist[x.second] + v.second < dist[v.first]){
				dist[v.first] = x.first + v.second;
				q.push({dist[v.first], v.first});
			}
		}
	}
	for(int i = 1; i <= V; ++i){
		cout << dist[i] << ' ';
	}
	cout << '\n';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		memset(adj, {}, sizeof(adj));
		cin >> V >> E >> U;
		for(int i = 0; i < E; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});

		}
		dijkstra();
	}

	return 0;
}

