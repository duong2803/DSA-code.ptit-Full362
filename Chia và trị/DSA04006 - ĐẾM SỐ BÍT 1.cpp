
// created: 2023-05-26 18:09:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, l, r;
vector<ll> pos;

ll solve(ll k, ll N = n, int idx = pos.size() - 1){
	if(k & 1) return 1;
	if(k < pos[idx]) 
		return solve(k, N / 2, idx - 1);
	if(k == pos[idx])
		return N % 2;
	return solve(pos[idx] * 2 - k, N / 2, idx - 1);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		pos.clear();
		cin >> n >> l >> r;

		ll tmp = n;
		ll x = 2;
		while(tmp >>= 1){
			pos.push_back(x);
			x <<= 1;
		}

		ll cnt = 0;
		for(ll i = l; i <= r; ++i){
			cnt += solve(i);
		}
		cout << cnt << '\n';
	}

	return 0;
}

