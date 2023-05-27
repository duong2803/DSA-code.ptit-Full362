
// created: 2023-05-26 18:16:23
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		vector<ll> pre = a;
		vector<ll> suf = a;
		for(int i = 1; i < n; ++i){
			ll mx = pre[i];
			for(int j = 0; j < i; ++j){
				if(a[i] > a[j]){
					mx = max(mx, pre[i] + pre[j]);
				}
			}
			pre[i] = mx;
		}
		for(int i = n - 2; ~i; --i){
			ll mx = suf[i];
			for(int j = n - 1; j > i; --j){
				if(a[i] > a[j]){
					mx = max(mx, suf[i] + suf[j]);
				}
			}
			suf[i] = mx;
		}

		ll res = LLONG_MIN;
		for(int i = 0; i < n; ++i){
			res = max(res, pre[i] + suf[i] - a[i]);
		}
		cout << res << '\n';
	}
    return 0;
}

