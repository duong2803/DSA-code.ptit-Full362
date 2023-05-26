
// created: 2023-05-26 18:07:24
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

unordered_map<ll, ll> f;

ll fib(ll n){
	if(f.find(n) != f.end())
		return f[n] % mod;
	if(n == 1 || n == 2) return 1;
	return f[n] = (fib((n - 1) / 2) * fib(n / 2) % mod + fib((n + 1) / 2) * fib((n + 2) / 2) % mod) % mod; 	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		ll n; 
		cin >> n;
		cout << fib(n) << '\n';
	}
	return 0;
}
