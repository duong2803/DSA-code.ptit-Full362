
// created: 2023-05-26 18:32:49
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
		sort(a.begin(), a.end());
		bool flag = false;
		for(int i = 0; i < n - 2; ++i){
			ll target = k - a[i];
			int l = i + 1;
			int r = n - 1;

			while(l < r){
				if(a[l] + a[r] == target){
					flag = true;
					break;
				}else{
					if(a[l] + a[r] < target){
						l++;
					}else
						r--;
				}
			}
			if(flag)
				break;
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}
	return 0;
}

