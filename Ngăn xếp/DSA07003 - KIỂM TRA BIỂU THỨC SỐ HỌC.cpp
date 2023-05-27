
// created: 2023-05-26 18:36:43
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();	
	while(t--){
		string s;
		getline(cin, s);	
		stack<char> st;
		bool flag = false;
		for(int i = 0; i < s.length(); ++i){
			if(st.empty()){
				st.push(s[i]);
				continue;
			}
			if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
				st.push(s[i]);
			}else if(s[i] == ')'){
				if(st.top() == '('){
					flag = true;
				}else{
					while(st.top() != '(')
						st.pop();
					st.pop();
				}
			}
		}
		if(flag){
			cout << "Yes";
		}else
			cout << "No";
		cout << '\n';
	}	

	return 0;
}

