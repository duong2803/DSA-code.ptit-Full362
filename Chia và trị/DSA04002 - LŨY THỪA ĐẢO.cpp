
// created: 2023-05-26 18:02:30
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
/*
ll Pow(ll n, ll k){

	ll res = 1;
	while(k){
		if(k & 1){
			res *= n;
			res %= mod;
		}
		n *= n;
		n %= mod;
		k /= 2;
	}
	return res;
}
*/

ll Pow(ll n, ll k){
	if(k == 0) return 1;
	if(k == 1) return n;
	ll tmp = Pow(n, k / 2);
	if(k & 1)
		return tmp % mod * tmp % mod * n % mod;
	return tmp % mod * tmp % mod;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string n;
		cin >> n;
		string s = n;
		reverse(s.begin(), s.end());
		cout << Pow(stoll(n), stoll(s)) % mod<< endl;
	
	}
	return 0;
}


