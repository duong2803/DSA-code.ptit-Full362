
// created: 2023-05-26 18:02:49
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 123456789;

ll Pow(ll n, ll k){
	ll res = 1;
	while(k){
		if(k&1){
			res *= n;
			res %= mod;
		}
		n *= n;
		n %= mod;
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
		ll n;
		cin >> n;
		cout << Pow(2, n - 1) << '\n';
	}	
	return 0;
}

