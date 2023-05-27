
// created: 2023-05-26 18:41:55
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string s1, s2;
		cin >> s1 >> s2;
		for(int i = 1; i < s1.length(); ++i){
			if(s1[i] == '(' && s1[i - 1] == '-'){
				for(int j = i + 1;; ++j){
					if(s1[j] == ')'){
						i = j;
						break;
					}	
					if(s1[j] == '-') s1[j] = '+';
					else if(s1[j] == '+') s1[j] = '-';
				}
			}
		}
		string s = "";
		for(int i = 0; i < s1.length(); ++i){
			if(s1[i] != '(' && s1[i] != ')')
				s += s1[i];
		}
		for(int i = 1; i < s2.length(); ++i){
			if(s2[i] == '(' && s2[i - 1] == '-'){
				for(int j = i + 1;; ++j){
					if(s2[j] == ')'){
						i = j;
						break;
					}	
					if(s2[j] == '-') s2[j] = '+';
					else if(s1[j] == '+') s2[j] = '-';
				}
			}
		}
		string ss = "";
		for(int i = 0; i < s2.length(); ++i){
			if(s2[i] != '(' && s2[i] != ')')
				ss += s2[i];
		}

		cout << (s == ss ? "YES" : "NO") << '\n';
	}

	return 0;
}

