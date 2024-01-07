
// created: 2023-05-26 17:30:26
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

string s;
void Sinh(){
	int i = s.length() - 1;
	while(i >= 0 && s[i] == '0')
		--i;
	if(i == -1){
		for(int j = 0; j < s.length(); ++j){
			cout << 1;
		}
		return;
	}
	s[i] = '0';
	for(int j = i + 1; j < s.length(); ++j)
		s[j] = '1';
	cout << s;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> s;
		Sinh();
		cout << '\n';
	}
	return 0;
}


