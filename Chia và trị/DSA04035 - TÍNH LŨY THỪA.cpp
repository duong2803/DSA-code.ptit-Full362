
// created: 2023-05-26 18:06:59
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	while(cin >> a >> b){
		if(a == 0 && b == 0)
			break;
		cout << Pow(a, b) << '\n';
	}
	return 0;
}

