
// created: 2023-05-26 18:40:39
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> a(n);	
		for(int i = 0; i < n; ++i) cin >> a[i];
		stack<int> st;
		vector<int> res(n);
		for(int i = 0; i < n; ++i){
			while(!st.empty() && a[st.top()] <= a[i]){
				int top = st.top(); st.pop();
				int l = st.empty() ? -1 : st.top();
				res[top] = top - l;	
			}
			st.push(i);
		}	
		while(!st.empty()){
			int top = st.top(); st.pop();
			int l = st.empty() ? -1 : st.top();
			res[top] = top - l;
		}
		for(int i: res)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}

