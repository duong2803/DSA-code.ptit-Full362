
// created: 2023-05-26 18:19:45
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		int dp[101][101] = {};
		for(int i = n - 2; ~i; --i){
			for(int j = i + 1; j < n; ++j){
				if(j == i + 1){
					if(s[i] != s[j]) dp[i][j] = 1;
				}else{
					if(s[i] == s[j])
						dp[i][j] = dp[i + 1][j - 1];
					else
						dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		cout << dp[0][n - 1] << '\n';
	}

	return 0;
}

