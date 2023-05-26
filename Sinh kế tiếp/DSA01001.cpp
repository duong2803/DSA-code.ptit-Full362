
// created: 2023-05-26 17:26:02
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

void S(){
	int i = s.length() - 1;
	while(s[i] == '1' && i >= 0){
		--i;
	}
	if(i == -1){
		for(int i = 0; i < s.length(); ++i){
			s[i] = '0';
		}
		return;
	}
	s[i] = '1';
	for(int j = i + 1; j < s.length(); ++j)
		s[j] = '0';

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> s;
		S();
		cout << s << '\n';
	}
	return 0;
}

