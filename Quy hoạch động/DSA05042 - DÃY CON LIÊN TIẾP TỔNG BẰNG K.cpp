
// created: 2023-05-26 18:20:04
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		int n;
		ll k;
		cin >> n >> k;	
		vector<ll> a(n + 1);
		vector<ll> pref(n + 1);
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			pref[i] = pref[i - 1] + a[i];
		}
		bool flag = false;
		unordered_set<ll> s;	
		for(int i = 0; i <= n; ++i){
			if(s.find(pref[i] - k) != s.end()){
				flag = true;
			}
			s.insert(pref[i]);
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}	
}

