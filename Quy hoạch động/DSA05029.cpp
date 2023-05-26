
// created: 2023-05-26 18:12:56
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
		string s;
		cin >> s;
		int n = s.length();
		vector<int> dp(n + 1);
		dp[n] = 1;
		dp[n - 1] = s[n - 1] != '0' ? 1 : 0;
		for(int i = n - 2; i >= 0; --i){
			if(s[i] == '0'){
				dp[i] = 0;
				continue;
			}
			dp[i] += dp[i + 1];
			if(s[i] == '1' || s[i] == '2' && s[i + 1] <= '6' && s[i + 1] >= '0'){
				dp[i] += dp[i + 2];
			}
		}

		cout << dp[0] << '\n';
    }
    return 0;
}

