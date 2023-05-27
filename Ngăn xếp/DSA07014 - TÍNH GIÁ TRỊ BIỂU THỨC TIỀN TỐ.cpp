
// created: 2023-05-26 18:37:47
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isOperator(char c){
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		reverse(s.begin(), s.end());
		for(char c: s){
			if(isOperator(c)){
				string op1 = st.top(); st.pop();
				string op2 = st.top(); st.pop();
				int tmp;
				if(c == '+'){
					tmp = stoi(op1) + stoi(op2);
				}else if(c == '-')
					tmp = stoi(op1) - stoi(op2);
				else if(c == '/')
					tmp = stoi(op1) / stoi(op2);
				else if(c == '*')
					tmp = stoi(op1) * stoi(op2);
				st.push(to_string(tmp));
			}else
				st.push(string(1,c));		
		}
		cout << st.top() << '\n';
	}
	return 0;
}

