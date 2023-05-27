
// created: 2023-05-26 23:39:03
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 9999999999;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){

		int V, E;
		cin >> V >> E;
		ll dp[101][101] = {};
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			dp[u][v] = 1;
		}
		
		for(int i = 1; i <= V; ++i){
			for(int j = 1; j <= V; ++j){
				if(i == j)
					dp[i][j] = 0;
				else if(!dp[i][j])
					dp[i][j] = INF;
			}
		}

		for(int k = 1; k <= V; ++k){
			for(int i = 1; i <= V; ++i){
				for(int j = 1; j <= V; ++j){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		ll sum = 0;
		ll cnt = 0;
		for(int i = 1; i <= V; ++i){
			for(int j = 1; j <= V; ++j){
				if(dp[i][j] != INF && i != j){
					sum += dp[i][j];
					++cnt;
				}
			}
		}
		cout << fixed << setprecision(2) << (sum / (double) cnt) << '\n';

	}

	return 0;
}

