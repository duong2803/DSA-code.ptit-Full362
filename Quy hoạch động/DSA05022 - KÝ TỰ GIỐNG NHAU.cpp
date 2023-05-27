
// created: 2023-05-26 18:17:19
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		// insert, delete, copy
		// 0 -> 1 -> 2 -> 4 -> 8 -> 9
		int dp[101];
		memset(dp, 0, sizeof(dp));
		dp[1] = x;
		for(int i = 2; i <= n; ++i){
			if(i & 1)
				dp[i] = min(dp[i - 1] + x, dp[i + 1 >> 1] + z + y);
			else
				dp[i] = min(dp[i >> 1] + z, dp[i - 1] + x);
		}
		cout << dp[n] << '\n';
	}

	return 0;
}

