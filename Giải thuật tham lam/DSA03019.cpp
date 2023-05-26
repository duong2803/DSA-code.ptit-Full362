
// created: 2023-05-26 17:57:50
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll p, ll q){
	if(p == 0 || q == 0){
		return;
	}
	if(q % p == 0){
		cout << "1/"  << q / p;
		return;
	}
	ll k = q / p + 1;
	cout << "1/" << k << " + ";
	solve(p * k - q, q * k);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		ll p, q;
		cin >> p >> q;
		solve(p, q);	
		cout << '\n';
	}

	return 0;
}

