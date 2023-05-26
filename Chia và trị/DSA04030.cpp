
// created: 2023-05-26 18:09:50
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
vector<vector<ll>> a = {{1,1,1,1}, {0,1,1,1}, {0,1,0,0}, {0,0,1,0}};
const ll mod = 1e15 + 7;

ll MulMod(ll a, ll b){
	ll res = 0;
	while(b){
		if(b & 1){
			res += a;
			res %= mod;
		}
		a *= 2;
		a %= mod;
		b /= 2;
	}
	return res;
}

vector<vector<ll>> Mul(vector<vector<ll>> &v1, vector<vector<ll>> &v2){
	vector<vector<ll>> res(4, vector<ll>(4));
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			ll tmp = 0;
			for(int k = 0; k < 4; ++k){
				tmp = tmp % mod + MulMod(v1[i][k],v2[k][j]);
				tmp %= mod;
			}
			res[i][j] = tmp;
		}
	}
	return res;
}

vector<vector<ll>> Pow(vector<vector<ll>> v, ll k){
	vector<vector<ll>> res = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	while(k){
		if(k & 1){
			res = Mul(res, v);
		}
		k /= 2;
		v = Mul(v, v);
	}
	return res;
}

void solve(){
	vector<vector<ll>> res = Pow(a, n);
	cout << res[0][2] << '\n';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> n;
		solve();
	}

	return 0;
}

