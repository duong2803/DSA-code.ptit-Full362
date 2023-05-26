
// created: 2023-05-26 18:22:39
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll C[1004][1004];

ll MulMod(ll a, ll b){
	return (a % mod * b % mod) % mod;
}

ll Pow(ll n, ll k){
	ll res = 1;
	while(k){
		if(k & 1){
			res *= n;
			res %= mod;
		}
		n *= n;
		n %= mod;
		k >>= 1;
	}
	return res;
}

ll inverseMod(ll n){
	return Pow(n, mod - 2);
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	C[0][0] = 1;

	for(int i = 1; i <= 1001; ++i){
		for(int j = 0; j <= i; ++j){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] %= mod;
		}
	}

	int t;
	cin >> t;
	
	while(t--){
		ll n, k;
		cin >> n >> k;
		
		vector<ll> dp(k + 1);
		dp[0] = n % mod;
		for(int i = 1; i <= k; ++i){
			dp[i] = Pow((n + 1) % mod, i + 1);
			dp[i] = (dp[i] - 1 + mod) % mod;
			for(int j = 0; j <= i - 1; ++j){
				dp[i] = dp[i] - MulMod(C[i + 1][j], dp[j]) + mod;
				dp[i] %= mod;
			}
			dp[i] = MulMod(dp[i], inverseMod(i + 1));
		}	
		cout << dp[k] << '\n';
		
	}
	return 0;
}


