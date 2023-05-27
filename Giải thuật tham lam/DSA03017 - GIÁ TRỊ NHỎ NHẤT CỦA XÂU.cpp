
// created: 2023-05-26 17:57:19
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
		int k;	
		string s;		
		cin >> k >> s;
		unordered_map<char, ll> mp;
		for(char c : s)
			mp[c]++;
		priority_queue<ll> q;
		for(auto p : mp)
			q.push(p.second);
		while(k--){
			ll tp = q.top(); q.pop();
			tp--;
			q.push(tp);
		}
		ll res = 0;
		while(!q.empty()){
			ll tp = q.top(); q.pop();
			res += tp * tp;
		}
		cout << res << '\n';
	}
	return 0;
}

