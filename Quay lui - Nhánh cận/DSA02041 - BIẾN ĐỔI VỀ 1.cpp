
// created: 2023-05-26 17:47:08
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
		int n;
		cin >> n;

		vector<int> dp(n + 1);
		for(int i = 2; i <= n; ++i){
			if(i % 2 == 0 && i % 3 == 0){
				dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3])) + 1;
			}
			else if(i % 2 == 0){
				dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
			}else if(i % 3 == 0){
				dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
			}else
				dp[i] = dp[i - 1] + 1;
		}
		cout << dp[n] << '\n';
	}
	return 0;
}

