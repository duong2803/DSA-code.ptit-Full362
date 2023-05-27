
// created: 2023-05-26 23:22:36
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string S, T;
set<string> st;

int dfs(){

	queue<pair<string,int>> q;
	q.push({S, 1});
	st.erase(S);
	while(!q.empty()){
		pair<string,int> fr = q.front(); q.pop();
		string s = fr.first;
		int cnt = fr.second;
		if(s == T) return cnt;
		for(int i = 0; i < s.length(); ++i){
			for(char j = 'A'; j <= 'Z'; ++j){
				string tmp = s;
				tmp[i] = j;
				if(st.find(tmp) != st.end()){
					q.push({tmp, cnt + 1});
					st.erase(tmp);
					if(tmp == T){
						return cnt + 1;
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n >> S >> T;
		for(int i = 0; i < n; ++i){
			string tmp;
			cin >> tmp;
			st.insert(tmp);
		}
		cout << dfs() << '\n';
	}
	return 0;
}

