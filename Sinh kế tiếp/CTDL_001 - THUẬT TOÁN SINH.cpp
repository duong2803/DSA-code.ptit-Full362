
// created: 2023-05-26 17:25:08
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

int n;

bool check(string &s){
	for(int i = 0; i <= n / 2; ++i){
		if(s[i] != s[n - i - 1])
			return false;
	}
	return true;
}

void backtrack(string s = "", int i = 0){
	if(i == n){
		if(check(s)){
			for(char c : s)
				cout << c << ' ';
			cout << '\n';
		}
		return;
	}
	backtrack(s + "0", i + 1);
	backtrack(s + "1", i + 1);
}

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	backtrack();
	return 0;
}

