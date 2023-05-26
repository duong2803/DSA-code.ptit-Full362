
// created: 2023-05-26 17:52:25
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		ll res = 0;
		for(int i = 0; i < n; ++i){
			res += a[i] * i;
			res %= mod;
		}
		cout << res << '\n';
	}

	return 0;
}

