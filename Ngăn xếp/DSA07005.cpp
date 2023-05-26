
// created: 2023-05-26 18:41:29
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
		string s;
		cin >> s;
		stack<int> st;
		for(int i = s.length() - 1; ~i; --i){
			if(s[i] == ')'){
				st.push(i);
			}
			if(s[i] == '('){
				int k = st.top(); st.pop();
				if(s[i - 1] == '-'){
					for(int j = i; j < k; ++j){
						if(s[j] == '-') s[j] = '+';
						else if(s[j] == '+') s[j] = '-';
					}
				}
			}
		}
		for(int i = 0; i < s.length(); ++i){
			if(s[i] != '(' && s[i] != ')')
				cout << s[i];
		}
		cout << '\n';
	}

	return 0;
}

