
// created: 2023-05-26 17:53:52
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
		int n = s.length();
		unordered_map<char, int> cnt;
		for(int i = 0; i < n; ++i)
			cnt[s[i]]++;
		bool flag = true;
		for(auto p : cnt){
			if(p.second > (n + 1) / 2)
				flag = false;
		}
		cout << (flag ? 1 : -1) << '\n';

	}
	
	return 0;
}

