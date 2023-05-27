
// created: 2023-05-26 18:14:20
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
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int dp[101][101][101];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n1; ++i){
			for(int j = 1; j <= n2; ++j){
				for(int k = 1; k <= n3; ++k){
					if(s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
						dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					else
						dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
		cout << dp[n1][n2][n3] << '\n';
	}
	return 0;	
}

