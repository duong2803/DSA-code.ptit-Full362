
// created: 2023-05-26 18:08:23
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
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		int l = n / 2 - 1;
		int r = n - 1;
		int res = n;
		while(~l){
			if(a[l] * 2 <= a[r]){
				res--;
				l--;
				r--;
			}else
				l--;
		}	
		cout << res << '\n';
	}

	return 0;
}

