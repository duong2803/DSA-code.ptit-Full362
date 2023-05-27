
// created: 2023-05-26 17:53:40
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> q;
		for(int i = 0; i < n; ++i){
			ll tmp;
			cin >> tmp;
			q.push(tmp);
		}
		ll res = 0;
		while(q.size() > 1){
			ll tp1 = q.top(); q.pop();
			ll tp2 = q.top(); q.pop();
			res += tp1 + tp2;
			q.push(tp1 + tp2);
		}
		cout << res << '\n';
		
	}
	
	return 0;
}

