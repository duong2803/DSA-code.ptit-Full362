
// created: 2023-05-26 18:14:33
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
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		vector<ll> dp = a;
		for(int i = 1; i < n; ++i){
			ll mx = a[i];
			for(int j = 0; j < i; ++j){
				if(a[i] > a[j]){
					mx = max(mx, dp[i] + dp[j]);
				}
			}
			dp[i] = mx;
		}
		ll res = dp[0];
		for(int i = 0; i < n; ++i)
			res = max(res, dp[i]);
		cout << res << '\n';
	}	

	return 0;
}

