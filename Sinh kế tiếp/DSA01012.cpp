
// created: 2023-05-26 17:34:56
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void Try(string s = "", int i = 0){
	if(i == n){
		string tmp(n, '0');
		tmp[0] = s[0];
		for(int i = n - 1; i >= 1; --i){
			if(s[i] != s[i - 1])
				tmp[i] = '1';
			else
				tmp[i] = '0';
		}
		cout << tmp << ' ';
		return;
	}
	Try(s + "0", i + 1);
	Try(s + "1", i + 1);
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	deque<int> q;
	while(t--){
		cin >> n;
		Try();
		cout << '\n';		
	}
	return 0;
}

