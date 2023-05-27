
// created: 2023-05-26 18:12:05
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

    while (t--)
    {
		int n, k;	
    	cin >> n >> k;
		ll dp[100001];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = i - min(i, k); j < i; ++j){
				dp[i] += dp[j];
				dp[i] %= mod;
			}
		}	
		cout << dp[n] << '\n';
	}
    return 0;
}

