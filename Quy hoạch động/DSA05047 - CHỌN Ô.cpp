
// created: 2023-05-26 18:20:30
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
int cnt = 0;
int n;


const ll mod = 1e9 + 7;
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
    int n;
	cin >> n;

	int a[4][10000];

	int res = INT_MIN;
	
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
			res = max(a[i][j], res);
		}
	}
	int ans = 0;

// 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111

	bool ok[16] = {true, true, true, false, true, true, false, false, true, true, true, false, false, false, false, false};
	int dp[10000][16];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 16; ++j){
			if(ok[j]){
				
				int s = 0;
				int tmp = j;
				for(int k = 0; k < 4; ++k){
					if(tmp & 1)
						s += a[k][i];
					tmp >>= 1;
				}
		
				if(i == 0){
					dp[i][j] = max(dp[i][j], s);
					continue;
				}
				for(int k = 0; k < 16; ++k){

					if(ok[k] && (k & j) == 0){
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + s);
						ans = max(ans, dp[i][j]);
					}
				}

			}
		}
	}

	
	if(ans)
		cout << ans;
	else
		cout << res;

	cout << '\n';
	}	
    return 0;

}
