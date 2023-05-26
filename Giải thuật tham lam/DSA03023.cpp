
// created: 2023-05-26 17:58:38
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int l = 0;
	int r = 0;	
	for(int i = 0; i < n; ++i){
		if(s[i] == 'X') ++l;
		if(s[i] == 'D') ++r;
	}	
	int cnt = 0, a = 0, b = 0;
	for(int i = 0; i < l; ++i){
		if(s[i] == 'T') ++cnt;
		if(s[i] == 'D') ++a;
	}

	for(int i = n - 1; i >= n - r; --i){
		if(s[i] == 'T') ++cnt;
		if(s[i] == 'X') ++b;
	}

	cout << cnt + max(a,b);

	return 0;
}

