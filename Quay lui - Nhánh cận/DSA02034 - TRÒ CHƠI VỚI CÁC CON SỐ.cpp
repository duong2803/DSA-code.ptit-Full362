
// created: 2023-05-26 17:42:58
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
		for(int i = 0; i < n; ++i){
			a[i] = i + 1;
		}
		do{
			bool flag = true;
			for(int i = 0; i < n - 1; ++i){
				if(abs(a[i] - a[i + 1]) == 1){
					flag = false;
				}
			}
			if(flag){
				for(int i : a){
					cout << i;
				}
				cout << '\n';
			}
		}while(next_permutation(a.begin(), a.end()));
	}
	return 0;
}

