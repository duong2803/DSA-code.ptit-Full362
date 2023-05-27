
// created: 2023-05-26 18:18:07
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
		string s1, s2;
		cin >> s1 >> s2;
		int dp[101][101];
		memset(dp, 0, sizeof(dp));
		int n1 = s1.length();
		int n2 = s2.length();
		for(int i = 0; i <= n1; ++i){
			for(int j = 0; j <= n2; ++j){
				if(i == 0){
					dp[i][j] = j;
				}else if(j == 0){
					dp[i][j] = i;
				}else{
					if(s1[i - 1] == s2[j - 1]){
						dp[i][j] = dp[i - 1][j - 1];
					}else
						dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				}
			}
		}
		cout << dp[n1][n2] << '\n';	
	}

	return 0;
}

