
// created: 2023-05-26 18:06:08
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
		ll n, k;
		cin >> n >> k;
		ll m = 1;	
		ll tmp = 1;
		for(int i = 1; i <= 50; ++i){
			if((k - tmp) % (2 * tmp) == 0){
				cout << (char) (i + 'A' - 1) << '\n';
				break;
			}
			tmp <<= 1;
		}
	}	
	return 0;
}

