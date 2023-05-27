
// created: 2023-05-26 18:22:23
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(string &s1, string &s2){
	if(s1.length() != s2.length()) return s1.length() < s2.length();
	return s1 < s2;
}

string make_str(string s, int k){
	string res;
	if(s == "0")
		res = to_string(k);
	else
		res = s + to_string(k);
	sort(res.begin(), res.end());
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
			
		int a, b;
		cin >> a >> b;
		string INF(100, '9');
		vector<vector<string>> dp(a + 1, vector<string>(b + 1, INF));
		dp[0][0] = "0";
		for(int i = 1; i <= a; ++i){
			for(int j = 1; j <= b; ++j){
				for(int k = 1; k * k <= min(i * i, min(j, 81)); ++k){
					if(dp[i - k][j - k * k] != INF){
						string tmp = make_str(dp[i - k][j - k * k], k);

						if(cmp(tmp, dp[i][j]))
							dp[i][j] = tmp;
					}
				}
			}
		}	
		if(dp[a][b] == INF)
			cout << -1;
		else
			cout << dp[a][b];
		cout << '\n';
	}

	return 0;
}

