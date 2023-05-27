
// created: 2023-05-26 18:38:42
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>> t;

	unordered_map<char, char> rules;
	rules.insert({')', '('});
	rules.insert({'}', '{'});
	rules.insert({']', '['});
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.length(); ++i){
			if(st.empty()){
				st.push(s[i]);
			}else{
				if(s[i] == '{' || s[i] == '(' || s[i] == '['){
					st.push(s[i]);
				}
				else if(rules[s[i]] == st.top())
					st.pop();
			}
		}
		cout << (st.empty() ? "YES" : "NO") << '\n';
	}	
	
	return 0;
}


