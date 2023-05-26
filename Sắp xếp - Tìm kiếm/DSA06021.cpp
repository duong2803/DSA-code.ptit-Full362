
// created: 2023-05-26 18:29:17
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
		int n, k;
		cin >> n >> k;
		int res = 0;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			if(a[i] == k) 
				res = i;
		}
		cout << res  + 1<< '\n';
	}
	return 0;
}

