
// created: 2023-05-26 17:31:13
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

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
		vector<int> b(n);
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		for(int i = 0; i < n; ++i)
			a[i] = i + 1;
		int cnt = 1;
		do{
			bool flag = true;
			for(int i = 0; i < n; ++i){
				if(a[i] != b[i])
					flag = false;
			}	
			if(flag){
				cout << cnt << '\n';
				break;
			}
			++cnt;
		}while(next_permutation(a.begin(), a.end()));

	}
	return 0;
}


