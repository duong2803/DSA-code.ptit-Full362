
// created: 2023-05-26 18:39:49
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
		int cur = 1;
		for(int i = 0; i < s.length(); ++i){
			if(s[i] == 'D'){
				st.push(cur);
				++cur;
			}else{
				cout << cur;
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
				++cur;
			}
		}
		cout << cur;
		while(!st.empty()){
			cout << st.top(); st.pop();
		}	
		cout << '\n';
	}

	return 0;
}

