
// created: 2023-05-26 18:43:14
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

		vector<int> a(n);
		vector<int> freq(n);
		unordered_map<int,int> cnt;
		for(int i = 0; i < n; ++i){
			cin >> a[i];	
			cnt[a[i]]++;
		}
		for(int i = 0; i < n; ++i){
			freq[i] = cnt[a[i]];
		}
		stack<int> st;
		vector<int> res(n);
		for(int i = 0; i < n; ++i){
			if(st.empty()){
				st.push(i);
				continue;
			}
			while(!st.empty() && freq[st.top()] < freq[i]){
				res[st.top()] = a[i];	
				st.pop();
			}
			st.push(i);
		}
		while(!st.empty()){
			res[st.top()] = -1;
			st.pop();
		}
		for(int i = 0; i < n; ++i)
			cout << res[i] << ' ';
		cout << '\n';
	}
	return 0;	
}

