
// created: 2023-05-26 18:40:04
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
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}	
		stack<int> st1;
		vector<int> b(n);
		for(int i = 0; i < n; ++i){
			while(!st1.empty() && a[st1.top()] < a[i]){
				int top = st1.top(); st1.pop();
				b[top] = i;	
			}
			st1.push(i);
		}
		while(!st1.empty()){
			int top = st1.top(); st1.pop();
			b[top] = -1;
		}
		stack<int> st2;
		vector<int> c(n);
		for(int i = 0; i < n; ++i){
			while(!st2.empty() && a[st2.top()] > a[i]){
				int top = st2.top(); st2.pop();
				c[top] = i;
			}
			st2.push(i);
		}	
		while(!st2.empty()){
			int top = st2.top(); st2.pop();
			c[top] = -1;
		}
		for(int i = 0; i < n; ++i){
			if(b[i] != -1){
				if(c[b[i]] != -1){
					cout << a[c[b[i]]] << ' ';
				}else
					cout << -1 << ' ';
			}
			else 
				cout << -1 << ' ';
		}
		cout << '\n';

	}

	return 0;
}

