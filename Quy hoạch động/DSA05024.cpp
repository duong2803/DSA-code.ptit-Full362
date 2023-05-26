
// created: 2023-05-26 18:17:54
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	
	while(t--){
		
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];	
		}
		vector<ll> dp(k + 1, 0);
		dp[0] = 1;
		for(int i = 1; i <= k; ++i){
			for(int j = 0; j < n; ++j){
				if(i - a[j] >= 0){
					dp[i] += dp[i - a[j]];
					dp[i] %= mod;	
				}
			}
		}

		cout << dp[k] << '\n';
	}
	return 0;
}

