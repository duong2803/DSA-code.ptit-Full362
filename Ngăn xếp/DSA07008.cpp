
// created: 2023-05-26 18:38:56
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isOperator(char c){
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t;
	cin >> t;

	unordered_map<char, int> priority;
	priority['+'] = priority['-'] = 1;
	priority['*'] = priority['/'] = 2;
	priority['^'] = 3;

	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		string res = "";
		
		for(char c : s){
			if(c == '('){
				st.push(c);
			}else if(c == ')'){
				while(!st.empty() && st.top() != '('){
					res += st.top();
					st.pop();
				}
				st.pop();
			}else if(isOperator(c)){
				while(!st.empty() && isOperator(st.top()) && priority[st.top()] >= priority[c]){
					res += st.top();
					st.pop();
				}
				st.push(c);
			}else{
				res += c;
			}
		}
		while(!st.empty()){
			char top = st.top();
			if(isOperator(top))
				res += top;
			st.pop();
		}	
		cout << res << '\n';
	}
	return 0;
}

