
// created: 2023-05-26 18:18:37
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
		int n;
		cin >> n;
		int dp[101][10];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= 9; ++i){
			dp[1][i] = 1;
		}
		for(int i = 2; i <= n; ++i){
			for(int j = 0; j <= 9; ++j){
				for(int k = 0; k <= j; ++k){
					dp[i][j] += dp[i - 1][k];
					dp[i][j] %= mod;
				}
			}
		}
		int res = 0;
		for(int i = 0; i <= 9; ++i){
			res += dp[n][i];
			res %= mod;
		}
		cout << res << '\n';
	}
	return 0;	
}

