
// created: 2023-05-26 17:29:18
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n, k;

void Try(string s = "", int i = 0, int K = k){
	
	if(K == 0){
		cout << s;
		for(int j = 0; j < n - i; ++j){
			cout << 0;
		}
		cout << '\n';
		return;
	}
	if(i == n){
		return;
	}
	Try(s + "0", i + 1, K);	
	if(K > 0){
		Try(s + "1", i + 1, K - 1);
	}
}

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
		cin >> n >> k;
		Try();
	}
	return 0;
}


