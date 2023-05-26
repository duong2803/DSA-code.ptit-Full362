
// created: 2023-05-26 18:18:49
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

		vector<pair<double, double>> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i].first >> a[i].second;
		}

		int dp[1000] = {};
		dp[0] = 1;
		int res = 1;
		for(int i = 1; i < n; ++i){
			dp[i] = 1;
			for(int j = 0; j < i; ++j){
				if(a[j].first < a[i].first && a[j].second > a[i].second){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}
		cout << res << '\n';
	}

	return 0;
}

