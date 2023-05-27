
// created: 2023-05-26 18:06:29
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
const ll mod = 1e9 + 7;
vector<vector<ll>> a;
vector<vector<ll>> Mul(vector<vector<ll>> &v1, vector<vector<ll>> &v2){
	
	vector<vector<ll>> res(n, vector<ll>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				res[i][j] += v1[i][k] * v2[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

vector<vector<ll>> Pow(){
	vector<vector<ll>> res(n, vector<ll>(n));
	for(int i = 0; i < n; ++i){
		res[i][i] = 1;
	}
	while(k){
		if(k & 1){
			res = Mul(res, a);
		}
		a = Mul(a, a);
		k >>= 1;
	}
	return res;
}

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
		a.resize(0,vector<ll>(0));
		cin >> n >> k;
		a.resize(n, vector<ll>(n));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> a[i][j];
			}
		}
		vector<vector<ll>> res = Pow();
		ll ans = 0;
		for(int i = 0; i < n; ++i){
			ans += res[i][n - 1];
			ans %= mod;
		}
		cout << ans << '\n';

	}	
	return 0;
}

