
// created: 2023-05-26 17:49:07
// author: Nguyen Tung Duong

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int c[25][25];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> c[i][j];
	}	
	
	int dp[1 << 16][16] = {};

	for(int mask = 1; mask < (1 << n - 1); ++mask){
		for(int i = 0; i < n - 1; ++i){
			if((mask >> i) & 1){
				if(__builtin_popcount(mask) == 1){
					dp[mask][i] = c[0][i + 1];
					break;
				}
				dp[mask][i] = 1e9;

				int pre_mask = mask - (1 << i);
				
				for(int j = 0; j < n - 1; ++j){
					if((pre_mask >> j) & 1){
						dp[mask][i] = min(dp[mask][i], dp[pre_mask][j] + c[j + 1][i + 1]);
					}
				}
			}
		}
	}

	int res = 1e9;
	for(int i = 0; i < n - 1; ++i){
		res = min(res, dp[(1 << n - 1) - 1][i] + c[i + 1][0]);
	}
	cout << res;

	return 0;
}



