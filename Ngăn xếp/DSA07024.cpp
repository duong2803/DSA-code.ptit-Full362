
// created: 2023-05-26 18:42:23
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
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		stack<ll> st;
		ll res = 0;
		for(int i = 0; i < n; ++i){

			while(!st.empty() && a[st.top()] >= a[i]){
				ll top = st.top(); st.pop();
				ll l = st.empty() ? -1 : st.top();
				if(a[top] <= i - l - 1){
					res = max(res, a[top]);
				}
			}
			st.push(i);
		}

		while(!st.empty()){
			ll top = st.top(); st.pop();
			ll l = st.empty() ? -1 : st.top();
			if(a[top] <= n - l - 1)
				res = max(res, a[top]);
		}
		cout << res << '\n';
	}
	return 0;	
}

