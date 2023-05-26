
// created: 2023-05-26 18:33:36
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


		int tmp;
		unordered_map<int, int> cnt;
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			cnt[tmp]++;
		}
		bool flag = false;
		int k = n / 2;

		int res;
		for(auto p : cnt){
			if(p.second > k){
				flag = true;
				res = p.first;
			}
		}
		if(flag){
			cout << res;
		}else
			cout << "NO";
		cout << '\n';

	}
	return 0;
}

