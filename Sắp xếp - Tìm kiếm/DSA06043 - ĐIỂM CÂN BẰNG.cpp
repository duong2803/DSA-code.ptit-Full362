
// created: 2023-05-26 18:33:48
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
		ll s = 0;
		vector<ll> a(n);
		vector<ll> prf(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			s += a[i];
			prf[i] = s;
		}	
		int res = -1;
		for(int i = 1; i < n - 1; ++i){
			ll tmp = s - a[i];
			if(tmp % 2 == 0){
				if(prf[i - 1] == tmp / 2){
					res = i + 1;
					break;
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}

