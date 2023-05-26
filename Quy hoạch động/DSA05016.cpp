
// created: 2023-05-26 18:16:10
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
		ll n;
		cin >> n; n--; 
		priority_queue<ll, vector<ll>, greater<ll>> q;
		q.push(1);
		unordered_set<ll> st;
		while(n--){
			ll top = q.top(); q.pop();
			if(st.find(top * 2) == st.end()){
				q.push(top * 2);
				st.insert(top * 2);
			}
			if(st.find(top * 3) == st.end()){
				q.push(top * 3);
				st.insert(top * 3);
			}
			if(st.find(top * 5) == st.end()){
				q.push(top * 5);
				st.insert(top * 5);
			}
		}	
		cout << q.top() << '\n';
	}

	return 0;
}

