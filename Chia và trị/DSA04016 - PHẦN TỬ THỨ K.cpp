
// created: 2023-05-26 18:04:06
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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n + m);	
		
		for(int i = 0; i < n + m; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		cout << a[k - 1] << '\n';
	}	
	return 0;
}

