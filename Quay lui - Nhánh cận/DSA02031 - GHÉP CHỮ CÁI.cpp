
// created: 2023-05-26 17:42:24
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char c;
	cin >> c;
	int n = c - 'A';
	string s = "";
	for(int i = 0; i <= n; ++i){
		s += 'A' + i;
	}

	do{
		bool flag = true;
		for(int i = 1; i < n; ++i){
			if(s[i] == 'A' || s[i] == 'E'){
				if(s[i - 1] != 'A' && s[i - 1] != 'E' && s[i + 1] != 'A' && s[i + 1] != 'E')
				  flag = false;	
			}
		}
		if(flag)
			cout << s << '\n';
	}while(next_permutation(s.begin(), s.end()));
	return 0;
}

