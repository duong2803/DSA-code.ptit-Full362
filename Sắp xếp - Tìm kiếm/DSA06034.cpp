
// created: 2023-05-26 18:32:18
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
		unordered_map<ll, int> cnt;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		ll count = 0;
		for(int i = 0; i < n; ++i){
			ll target = k - a[i];
			if(cnt.find(target) != cnt.end()){
				count += cnt[target];
			}
			cnt[a[i]]++;
		}
		cout << count << '\n';
	}
	return 0;
}

