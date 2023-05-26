
// created: 2023-05-26 18:32:06
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
		
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		vector<int> pre(n);
		vector<int> suf(n);
		pre[0] = a[0];
		for(int i = 1; i < n; ++i){
			pre[i] = min(pre[i - 1], a[i]);
		}
		suf[n - 1] = a[n - 1];
		for(int i = n - 2; ~i; --i){
			suf[i] = max(suf[i + 1], a[i]);
		}
		int l = 0;
		int r = 0;

		int res = -1;
		while(l < n && r < n){
			if(suf[r] > pre[l]){
				res = max(res, r - l);
				r++;
			}else{
				l++;
			}
		}
		cout << res << '\n';
	}
	return 0;
}

