
// created: 2023-05-26 18:21:02
// author: Nguyen Tung Duong

#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
	
int main(int argc, char *argv[])
{
	int t;
	cin >> t; 
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		int dp[1001][51];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < k; ++j){
					int m = (k -(a[i - 1] % k) + j)% k;
					if(dp[i - 1][m] == 0 && dp[i - 1][j] == 0){
						if(a[i - 1] % k == j){
							dp[i][j] = 1;
						}
					}else{
						dp[i][j] = max(dp[i-1][j], dp[i - 1][m] + 1);
					}
			}
			
		}
		cout << dp[n][0] << '\n';
	}

}
