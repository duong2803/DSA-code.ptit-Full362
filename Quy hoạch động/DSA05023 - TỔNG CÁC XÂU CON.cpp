
// created: 2023-05-26 18:17:40
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
	
		string s;
		cin >> s;
			
		ll res = 0;
		int n  = s.length();
		for(int i = 0; i < n; ++i){
			string s1 = "";
			for(int j = i; ~j; --j){
				s1 = s[j] + s1;
				res += stoll(s1);
			}
		}
		cout << res << '\n';
	}
	return 0;
}


