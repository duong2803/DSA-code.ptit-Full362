
// created: 2023-05-26 18:21:33
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
		vector<pair<int,int>> a(n);

		for(int i = 0; i < n; ++i){
			cin >> a[i].first >> a[i].second;
		}

		sort(a.begin(), a.end());

		vector<int> dp(n, 0);
		dp[0] = 1;

		for(int i = 1; i < n; ++i){
			dp[i] = 1;
			for(int j = 0; j < i; ++j){
				if(a[i].first > a[j].second){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}

		}
		int res = INT_MIN;
		for(int i = 0; i < n; ++i)
			res = max(res, dp[i]);
		cout << res << '\n';
	}
	
	return 0;
}

