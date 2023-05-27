
// created: 2023-05-26 18:41:42
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
vector<pair<int,int>> pos;
set<string> res;

void Try(int i = 0, string k = ""){

	if(i == pos.size()){
		if(k == string(pos.size(),'0')) return;
		unordered_set<int> st;
		for(int j = 0; j < pos.size(); ++j){
			if(k[j] == '1'){
				st.insert(pos[j].first);
				st.insert(pos[j].second);
			}
		}

		string tmp = "";
		for(int j = 0; j < s.length(); ++j){
			if(st.find(j) == st.end()){
				tmp += s[j];
			}
		}
		res.insert(tmp);
		return;
	}

	Try(i + 1, k + "0");
	Try(i + 1, k + "1");	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	stack<int> st;

	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '(')
			st.push(i);
		if(s[i] == ')'){
			pos.push_back({st.top(), i});
			st.pop();
		}
	}

	Try();
	for(string i: res){
		cout << i << '\n';
	}
	return 0;
}

