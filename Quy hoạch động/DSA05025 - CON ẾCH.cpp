
// created: 2023-05-26 18:12:17
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
		int n;
		cin >> n;
		ll dp[100];
		memset(dp, 0, sizeof(dp));	
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for(int i = 4; i <= n; ++i){
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}
    return 0;
}

