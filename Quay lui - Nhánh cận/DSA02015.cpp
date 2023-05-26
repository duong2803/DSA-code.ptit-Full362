
// created: 2023-05-26 17:48:49
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(string s){
	if(s.length() == 0) return false;
	if(s.length() == 1 && s[0] != ')' && s[0] != '(') return false;
	int deg = 0;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '(') ++deg;
		if(s[i] == ')') --deg;
		if(deg < 0) return false;
	}
	return deg == 0;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		
		string s;
		cin >> s;
		queue<string> q;
		q.push(s);
		unordered_set<string> st;	
		st.insert(s);
		vector<string> res;
		bool flag = false;
		while(!q.empty()){
			string front = q.front(); q.pop();
			if(check(front)){
				res.push_back(front);
				flag = true;
			}	
			if(flag) continue;
			for(int i = 0; i < front.length(); ++i){
				if(front[i] != '(' && front[i] != ')') continue;
				string tmp = front.substr(0, i) + front.substr(i + 1);
				if(st.find(tmp) == st.end()){
					st.insert(tmp);
					q.push(tmp);
				}
			}
		}
		sort(res.begin(), res.end());
		if(res.size() == 0)
			cout << -1;
		else{
			for(string i : res)
				cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}

