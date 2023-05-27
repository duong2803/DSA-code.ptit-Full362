
// created: 2023-05-26 18:21:18
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		dp[0][0] = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= k; ++j){
				for(int x = 0; x <= min(j, 9); ++x){
					dp[i][j] += dp[i - 1][j - x];
					dp[i][j] %= mod;
				}
			}
		}
		cout << dp[n][k] << '\n';
	}

	return 0;
}

