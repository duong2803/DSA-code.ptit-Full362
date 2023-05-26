
// created: 2023-05-26 18:04:18
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
			
		vector<int> a(n), b(n - 1);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n - 1; ++i)
			cin >> b[i];
		bool flag= true;
		for(int i = 0; i < n - 1; ++i){
			if(a[i] != b[i]){
				cout << i + 1;
				flag = false;
				break;
			}
		}
		if(flag){
			cout << n;
		}
		cout << '\n';
	}	
	return 0;
}

