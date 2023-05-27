
// created: 2023-05-26 18:14:05
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}	
		vector<ll> dp(n);
		dp[0] = a[0];
		dp[1] = max(a[0], a[1]);
		for(int i = 2; i < n; ++i){
			dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
		}
		cout << dp[n - 1] << '\n';
	}	

    return 0;
}

