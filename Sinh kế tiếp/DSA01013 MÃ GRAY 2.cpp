
// created: 2023-05-26 17:35:14
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

	deque<int> q;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		string res(n, '0');
		res[0] = s[0];
		for(int i = 1; i < n; ++i){
			if(s[i] == '1'){
				res[i] = res[i - 1] == '1' ? '0' : '1';
			}else
				res[i] = res[i - 1];
		}
		cout << res << '\n';
	}
	return 0;
}

