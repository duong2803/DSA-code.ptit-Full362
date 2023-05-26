
// created: 2023-05-26 17:36:21
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
		string s;
		cin >> s;
		int n = s.length();
		string res(n, '0');
		res[0] = s[0];
		for(int i = n - 1; i >= 1; --i){
			if(s[i] != s[i - 1])
				res[i] = '1';
			else
				res[i] = '0';
		}
		cout << res << '\n';
	}	
}

