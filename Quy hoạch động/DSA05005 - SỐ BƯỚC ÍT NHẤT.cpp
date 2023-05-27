
// created: 2023-05-26 18:11:13
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;


int main(){

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
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}	
		vector<int> dp(n);
		dp[0] = 1;
		for(int i = 0; i < n; ++i){
			dp[i] = 1;
			for(int j = 0; j < i; ++j){
				if(a[j] <= a[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int m = 1;
		for(int i = 0; i < n; ++i){
			m = max(m, dp[i]);
		}
		cout << n - m << '\n';
	}	
	return 0;
}

