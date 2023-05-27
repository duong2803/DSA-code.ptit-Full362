
// created: 2023-05-26 18:40:51
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
		stack<string> st;

		for(int i = 0; i < s.length(); ++i){
			if(s[i] >= '0' && s[i] <= '9'){
				if(st.empty()){
					st.push(string(1, s[i]));
				}else if(st.top()[0] >= '0' && st.top()[0] <= '9'){
					string top = st.top(); st.pop();
					st.push(top + string(1, s[i]));
				}else{
					st.push(string(1, s[i]));
				}
			}else if(s[i] != '[' && s[i] != ']'){
				if(st.empty()){
					st.push(string(1, s[i]));
				}
				else if(st.top()[0] < '0' || st.top()[0] > '9'){
					string top = st.top(); st.pop();	
					st.push(top + string(1, s[i]));
				}else{
					st.push(string(1, s[i]));
				}
			}
			if(s[i] == ']'){
				string s1 = st.top(); st.pop();
				int k;
				if(st.empty()){
					k = 1;
				}else{
					k = stoi(st.top()); st.pop();
				}
				string tmp = "";
				while(k--){
					tmp += s1;
				}
				if(!st.empty()){
					string top = st.top(); st.pop();
					st.push(top + tmp);
				}else
					st.push(tmp);
			}
		}
		cout << st.top() << '\n';
	}
	return 0;
}


