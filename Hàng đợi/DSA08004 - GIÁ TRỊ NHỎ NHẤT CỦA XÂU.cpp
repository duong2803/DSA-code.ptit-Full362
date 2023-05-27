
// created: 2023-05-26 23:20:41
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int k;
		cin >> k;	
		string s;
		cin >> s;
		unordered_map<char,int> mp;
		for(char c: s)
			mp[c]++;
		priority_queue<ll> q;
		for(auto p : mp)
			q.push(p.second);
		ll res = 0;
		while(k--){
			ll top = q.top(); q.pop();
			top--; q.push(top);
		}
		while(!q.empty()){
			res += q.top() * q.top(); q.pop();
		}
		cout << res << '\n';
	}

	return 0;
}

