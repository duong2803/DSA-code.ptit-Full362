
// created: 2023-05-26 18:08:58
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		ll res = 0;
		for(int i = 0; i < n - 1; ++i){
			int l = i + 1;
			int r = n - 1;
			int idx = i;
			while(l <= r){
				int m = l + r >> 1;
				if(a[m] - a[i] < k){
					idx = m;
					l = m + 1;
				}else
					r = m - 1;
			}
			res += idx - i;
		}
		cout << res << '\n';
	}	

	return 0;
}

