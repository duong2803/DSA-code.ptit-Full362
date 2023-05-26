
// created: 2023-05-26 18:12:29
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

	ll c, n;
	cin >> c >> n;
	vector<ll> a(n);

	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	ll dp[25001];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; ++i){
		for(int j = c; j >= a[i]; --j){
			dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
		}
	}
	cout << dp[c];

    return 0;
}

