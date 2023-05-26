
// created: 2023-05-26 18:03:23
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

	ll fib[93];
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= 92; ++i){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int t;
	cin >> t;

	while(t--){
		ll n, k;
		cin >> n >> k;
		while(n > 2){
			if(k <= fib[n - 2]){
				n -= 2;
			}else{
				k -= fib[n - 2];
				n -= 1;
			}
		}
		if(n == 1)
			cout << 'A';
		else if(n == 2)
			cout << 'B';
		cout << '\n';
	}	
	return 0;
}

