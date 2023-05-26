
// created: 2023-05-26 18:11:35
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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		bool dp[201][40001];
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j <= k; ++j){
				if(j == 0){
					dp[i][j] = true;
				}else{
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]]; 
				}
			}
		}	
		cout << (dp[n][k] ? "YES" : "NO") << '\n';
	}	
	return 0;
}

