
// created: 2023-05-26 18:13:50
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
		int n, w;
		cin >> n >> w;
		vector<int> a(n);
		vector<int> c(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> c[i];
		vector<int> dp(w + 1);
		for(int i = 0; i < n; ++i){
			for(int j = w; j >= a[i]; --j){
				dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
			}
		}
		cout << dp[w] << '\n';
	}	

    return 0;
}

