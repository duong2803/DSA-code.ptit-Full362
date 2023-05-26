
// created: 2023-05-26 18:34:00
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);	
		ll res = LLONG_MAX;	
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}	
		sort(a.begin(), a.end());
		for(int i = 0; i < n - 1; ++i){
			res = min(res, a[i + 1] - a[i]);
		}
		cout << res << '\n';
	}
	return 0;
}

