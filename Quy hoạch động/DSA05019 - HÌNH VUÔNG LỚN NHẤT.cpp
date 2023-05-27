
// created: 2023-05-26 18:16:46
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

		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> a[i][j];
			}
		}
		int res = 0;
		vector<vector<int>> dp(n, vector<int>(m));
		for(int i = n - 1; ~i; --i){
			for(int j = m - 1; ~j; --j){
				if(i == n - 1 || j == m - 1){
					if(a[i][j] == 1){
						dp[i][j] = 1;
					}
				}else{
					if(a[i][j] == 1){
						int a1 = dp[i + 1][j];
						int a2 = dp[i][j + 1];
						int a3 = dp[i + 1][j + 1];
						dp[i][j] = min(a1, min(a2,a3)) + 1;
					}
				}
				res = max(res, dp[i][j]);
			}
		}

		cout << res << '\n';
	}

	return 0;
}

