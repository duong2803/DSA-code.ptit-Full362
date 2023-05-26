
// created: 2023-05-26 17:57:06
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int s, n;

void solve(){
	vector<int> a(n);

	if(n * 9 < s){
		cout << -1;
		return;
	}
	s -= 1;
	for(int i = n - 1; i >= 1; --i){
		if(s >= 9){
			a[i] = 9;
			s -= 9;
		}else{
			a[i] = s;
			s = 0;
			break;
		}
	}
	a[0] = s + 1;
	for(int i : a){
		cout << i;
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
		cin >> s >> n;
		solve();
		cout << '\n';	
	}

	return 0;
}


