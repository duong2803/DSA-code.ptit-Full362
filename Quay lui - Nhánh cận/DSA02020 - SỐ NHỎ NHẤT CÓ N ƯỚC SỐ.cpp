
// created: 2023-05-26 17:50:31
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> prime;
ll res;
ll n;

void Try(ll cnt = 1, ll pr = 0, ll k = 1){

	if(cnt == n){
		res = min(res, k);
		return;
	}

	for(int i = 1;; ++i){
		if(cnt * (i + 1) > n || k * pow(prime[pr],i) > res) return;
		Try(cnt * (i + 1), pr + 1, k * pow(prime[pr], i));
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<bool> sieve(51, true);
	for(int i = 2; i * i <= 50; ++i){
		if(sieve[i]){
			for(int j = i * i; j <= 50; j += i){
				sieve[j] = false;
			}
		}
	}
	for(ll i = 2; i <= 50; ++i){
		if(sieve[i])
			prime.push_back(i);
	}
	int t;
	cin >> t;
	while(t--){
		res = LLONG_MAX;
		cin >> n;
		Try();
		cout << res << '\n';
	}
	return 0;
}

