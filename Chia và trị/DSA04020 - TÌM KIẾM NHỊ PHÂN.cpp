
// created: 2023-05-26 18:04:41
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
		
		int n, k;
		cin >> n  >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		auto it = lower_bound(a.begin(), a.end(), k);
		if(it == a.end()){
			cout << "NO";
		}else{
			if(*it == k){
				cout << it - a.begin() + 1;
			}else{
				cout << "NO";
			}
		}
		
		cout << '\n';
	}	
	return 0;
}

