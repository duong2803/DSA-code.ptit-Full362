
// created: 2023-05-26 18:38:00
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
		cin >> s;	

		int n = s.length();
		stack<int> st;
		int res = 0;
		for(int i = 0; i < n; ++i){
			if(st.empty()){
				st.push(i);
				continue;	
			}
			if(s[i] == '('){
				st.push(i);
			}else{
				if(s[st.top()] == '('){
					st.pop();
					int l = st.empty() ? -1 : st.top();
					res = max(res, i - l);
				}else
					st.push(i);
			}
		}
		cout << res << '\n';	
	}	

	return 0;
}

