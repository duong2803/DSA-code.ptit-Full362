
// created: 2023-05-26 18:34:26
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
		vector<ll> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		int k = 0;
		while(a[k] < a[k + 1] && k < n - 1)
			++k;
		if(k == n - 1){
			cout << 0;
		}else{
			if(a[0] == a[n - 1]){
				cout << 0;
			}else{
				cout << k + 1;
			}
		}
		cout << '\n';
	}
	return 0;
}

