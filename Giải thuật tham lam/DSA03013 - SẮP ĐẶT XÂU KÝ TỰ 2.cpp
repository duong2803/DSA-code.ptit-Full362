
// created: 2023-05-26 17:54:09
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
		cin >> k;
		string s;
		cin >> s;
		int n = s.length();
		bool flag = true;
		unordered_map<char, int> cnt;
		for(char c: s)
			cnt[c]++;
		for(auto p : cnt){
			if(p.second > (n + 1) / k)
				flag = false;
		}
		cout << (flag ? 1 : -1) << '\n';
	}
	
	return 0;
}

