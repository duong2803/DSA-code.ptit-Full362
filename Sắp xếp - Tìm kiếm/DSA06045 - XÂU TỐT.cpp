
// created: 2023-05-26 18:35:41
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll cnt = 0;
	for(int i = 0; i < n - 1; ++i){
		if(s[i] != s[i + 1]){
			++cnt;
			int it1 = i;
			int it2 = i + 1;
			while(it1 > 0 && s[it1] == s[it1 - 1]) {
				++cnt;
				--it1;
			}
			while(it2 < n - 1&& s[it2] == s[it2 + 1]){
				++cnt;
				++it2;
			}
		}
	}
	cout << n * (n - 1) / 2 - cnt; 

	return 0;
}

