
// created: 2023-05-26 17:55:17
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
		vector<pair<ll,ll>> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i].first >> a[i].second;
		
		sort(a.begin(), a.end(), [](pair<ll,ll> &p1, pair<ll,ll> &p2){
			if(p1.second == p2.second) return p1.first < p2.first;
			return p1.second < p2.second;
		});

		ll res = 0;
		for(int i = 0; i < n; ++i){

			ll endTime = a[i].second;
			while(i < n && a[i].first < endTime){
				++i;
			}
			--i;
			++res;
		}
		cout << res << '\n';

	}
	return 0;
}

