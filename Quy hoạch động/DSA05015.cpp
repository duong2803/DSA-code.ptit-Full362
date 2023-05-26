
// created: 2023-05-26 18:15:56
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
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

ll inverseMod(ll n){
	return Pow(n, mod - 2);
}

ll f(ll n){
	ll res = 1;
	for(ll i = 2; i<= n; ++i){
		res *= i;
		res %= mod;
	}
	return res;
}

ll C(ll n, ll k){
	return f(n) * inverseMod(f(n - k)) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
		ll n, k;
		cin >> n >> k;
		cout << C(n, k) % mod << '\n';		
    }
    return 0;
}

