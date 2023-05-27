
// created: 2023-05-26 17:59:05
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_set<ll> st;
string S;
ll res = -1;
void Try(string s = "", int i = 0){

	if(i == S.length()){
		if(s.length() > 0){
			if(st.find(stoll(s)) != st.end()){
				res = max(res, stoll(s));
			}
		}
		return;
	}

	Try(s + S[i], i + 1);
	Try(s, i + 1);
}	

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for(ll i = 1; i <= 100; ++i){
		st.insert(i * i * i);	
	}

	while(t--){
		res = -1;
		cin >> S;
		Try();	
		cout << res << '\n';
	}

	return 0;
}

