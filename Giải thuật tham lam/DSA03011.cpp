
// created: 2023-05-26 17:56:39
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

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
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> q;
		ll tmp;
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			q.push(tmp);
		}
		ll res = 0;
		while(q.size() > 1){
			ll tp1 = q.top(); q.pop();
			ll tp2 = q.top(); q.pop();
			ll k = (tp1 % mod + tp2 % mod) % mod;
			res += k;
			q.push(k);
			res %= mod;
		}
		cout << res << '\n';
	}
	return 0;
}

