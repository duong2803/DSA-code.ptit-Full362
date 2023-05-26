
// created: 2023-05-26 17:59:25
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll sm = 0;
	for(int i = 0; i < n; ++i){
		ll tmp;
		cin >> tmp;
		sm += tmp + abs(tmp);
	}
	cout << sm;
	return 0;
}

