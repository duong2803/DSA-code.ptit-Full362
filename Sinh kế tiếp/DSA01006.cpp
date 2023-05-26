
// created: 2023-05-26 17:28:02
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
		for(int i = 0; i < n; ++i){
			a[i] = n - i;
		}
		do{
			for(int i : a){
				cout << i;
			}
			cout << ' ';
		}while(prev_permutation(a.begin(), a.end()));
		cout << '\n';
	}
	return 0;
}


