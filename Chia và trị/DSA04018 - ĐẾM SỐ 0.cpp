
// created: 2023-05-26 18:04:29
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
		auto it = upper_bound(a.begin(), a.end(), 0);
		if(it == a.end()){
			cout << n;
		}else{
			cout << it - a.begin();
		}
		cout << '\n';
	}	
	return 0;
}

