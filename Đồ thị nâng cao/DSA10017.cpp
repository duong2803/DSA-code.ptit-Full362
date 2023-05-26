
// created: 2023-05-26 23:39:28
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct Edge{
	ll u, v, w;
};

vector<Edge> edges;
const ll mxN = 1001;
ll V, E;
bool flag;

void BellmanFord(){
	vector<ll> dist(V + 1, - 1);
	int x;
	for(int i = 0; i < V - 2; ++i){
		x = -1;
		for(Edge e: edges){
			if(dist[e.u] + e.w < dist[e.v]){
				dist[e.v] = dist[e.u] + e.w;
				x = 0;
			}
		}
	}	
	if(x == 0) flag = true;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	
	while(t--){
		flag = false;
		cin >> V >> E;
		edges.clear();
		for(ll i = 0; i < E; ++i){
			ll u, v, w;
			cin >> u >> v >> w;
			Edge e = {u, v, w};
			edges.push_back(e);
		}		
		BellmanFord();
		cout << (flag ? 1 : 0) << '\n';
	}
	return 0;
}
