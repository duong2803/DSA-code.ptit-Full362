
// created: 2023-05-26 18:38:29
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
		int n;
		cin >> n;
		vector<int> a(n);
		stack<int> st;
		for(int i = 0; i < n; ++i) cin >> a[i];
		vector<int> res(n);
		for(int i = 0; i < n; ++i){
			while(!st.empty() && a[st.top()] < a[i]){
				res[st.top()] = a[i];
				st.pop();
			}
			st.push(i);
		}	
		while(!st.empty()){
			res[st.top()] = -1;
			st.pop();
		}
		for(int i: res)
			cout << i << ' ';
		cout << '\n';
	}	

	return 0;
}

