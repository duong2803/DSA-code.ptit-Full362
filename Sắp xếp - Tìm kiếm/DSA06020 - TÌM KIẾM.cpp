
// created: 2023-05-26 18:29:05
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
		cin >> n >> k;
		int tmp;
		bool flag = false;
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			if(tmp == k)
				flag = true;
		}
		cout << (flag ? 1 : -1) << '\n';
		
	}
	return 0;
}

