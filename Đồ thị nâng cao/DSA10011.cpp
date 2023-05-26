
// created: 2023-05-26 23:38:49
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 250001;
const int INF = 1e9;
int V, E, U;
int n, m;
vector<pair<int,int>> adj[mxN];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int X;
int a[501][501];
int mp(int x, int y){
	return m * (x - 1) + y;
}

void dijkstra(){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	vector<int> dist(V + 10, INF);
	dist[1] = X;
	q.push({X, 1});
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
	cout << dist[V] << '\n';
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		memset(adj, {}, sizeof(adj));
		cin >> n >> m;
		V = n * m;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cin >> a[i][j];
			}
		}
		X = a[1][1];
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				for(int k = 0; k < 4; ++k){
					int ii = i + dx[k];
					int jj = j + dy[k];
					if(ii >= 1 && ii <= n && jj >= 1 && jj <= m){
						adj[mp(i,j)].push_back({mp(ii, jj), a[ii][jj]});
					}
				}
			}
		}
		dijkstra();	
	}

	return 0;
}

