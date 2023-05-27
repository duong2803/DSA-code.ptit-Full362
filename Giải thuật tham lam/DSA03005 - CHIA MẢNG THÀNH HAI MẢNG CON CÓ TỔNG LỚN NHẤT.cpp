
// created: 2023-05-26 17:52:49
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
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		k = min(k, n - k);
		ll s1 = 0, s2 = 0;
		for(int i = 0; i < k; ++i)
			s1 += a[i];
		for(int i = k; i < n; ++i)
			s2 += a[i];	
		cout << s2 - s1 << '\n';
	}

	return 0;
}

