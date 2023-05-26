
// created: 2023-05-26 23:38:38
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V, E;
	cin >> V >> E;
	ll dp[101][101] = {};
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < E; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		dp[u][v] = dp[v][u] = w;
	}
	
	for(int i = 1; i <= V; ++i){
		for(int j = 1; j <= V; ++j){
			if(i == j)
				dp[i][j] = 0;
			else if(!dp[i][j])
				dp[i][j] = 9999999999;
		}
	}

	for(int k = 1; k <= V; ++k){
		for(int i = 1; i <= V; ++i){
			for(int j = 1; j <= V; ++j){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}



	int q;
	cin >> q;	

	while(q--){
		int U, V;
		cin >> U >> V;
		cout << dp[U][V] << '\n';
	}

	return 0;
}

