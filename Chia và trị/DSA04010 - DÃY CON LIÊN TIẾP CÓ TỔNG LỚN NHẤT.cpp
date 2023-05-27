
// created: 2023-05-26 18:03:36
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;		
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		int res = INT_MIN;
		int tmp = 0;
		for(int i = 0; i < n; ++i){
			tmp += a[i];
			res = max(res, tmp);
			if(tmp < 0)
				tmp = 0;
		}
		cout << res << '\n';
	}	
	return 0;
}

