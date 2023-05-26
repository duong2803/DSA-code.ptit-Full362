
// created: 2023-05-26 18:18:20
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
		iota(dp.begin(), dp.end(), 0);
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j * j <= i; ++j){
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		cout << dp[n] << '\n';
	}
	return 0;	
}

