
// created: 2023-05-26 18:31:54
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
		ll k;
		cin >> n >> k;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];	
	   	ll cnt = 0;
		sort(a.begin(), a.end());
		for(int i = 0; i < n - 2; ++i){
			ll target = k - a[i];
			int l = i + 1;
			int r = n - 1;
			while(l < r){
				ll sum = a[l] + a[r];
				if(sum >= target){
					r--;
				}else{
					cnt = cnt + (r - l);
					++l;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

