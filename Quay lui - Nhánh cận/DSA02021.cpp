
// created: 2023-05-26 17:50:44
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;

	while(t--){
		string s;
		ll k;
		cin >> s >> k;
		ll n = s.length();
		while(n < k) n <<= 1;
		while(k > s.length()){
			ll m = n >> 1;
			if(k > m){
				if(k == m + 1)
					--k;
				else
					k -= m + 1;
			}
			n >>= 1;
		}
		cout << s[k - 1] << '\n';
	}

	return 0;
}

