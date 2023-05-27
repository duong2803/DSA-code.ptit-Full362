
// created: 2023-05-26 18:10:35
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
		string s1, s2;
		cin >> s1 >> s2;
		int n1 = s1.length();
		int n2 = s2.length();
		int dp[1001][1001];
		for(int i = 1; i <= n1; ++i){
			for(int j = 1; j <= n2; ++j){
				if(s1[i - 1] == s2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[n1][n2] << '\n';

	}
	return 0;
}

