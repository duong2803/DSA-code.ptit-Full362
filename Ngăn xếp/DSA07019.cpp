
// created: 2023-05-26 18:40:20
// author: Nguyen Tung Duong

#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
	
int main(int argc, char *argv[])
{
	int t;
	cin >> t; 
	
	while(t--){
		ll m;
		cin >> m;
		ll res = 0;
		vector<int> a(m);
		for(int i = 0; i < m; ++i)
			cin >> a[i];
			stack<ll> st;
			for(ll j = 0; j < m; ++j){
				
				while(!st.empty() && a[j] <= a[st.top()]){
					ll top = st.top(); st.pop();
					ll l = st.empty() ? -1 : st.top();
				  	res = max(res, (j - l - 1) * a[top]);	
				}
				st.push(j);	
			}
		while(!st.empty()){
					ll top = st.top(); st.pop();
					ll l = st.empty() ? -1 : st.top();
				  	res = max(res, (m - l - 1) * a[top]);	
				}
		cout << res << '\n';
	}

}
