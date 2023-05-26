
// created: 2023-05-26 18:21:50
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll dp[26][26];

	for(int i = 0; i < 26; ++i){
		dp[0][i] = 1;
		dp[i][0] = 1;
	}
	for(int i = 1; i < 26; ++i){
		for(int j = 1; j < 26; ++j){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}

	}
	
	int t;
	cin >> t;

	while(t--){
		ll a, b;
		cin >> a >> b;	
		cout << dp[a][b] << '\n';
	}

	return 0;
}


