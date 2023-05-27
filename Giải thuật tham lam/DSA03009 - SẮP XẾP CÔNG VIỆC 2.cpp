
// created: 2023-05-26 17:56:15
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		vector<int> adj[1001];
		for(int i = 0; i < n; ++i){
			int a,b,c;
			cin >> a >> b >> c;
			adj[b].push_back(c);
		}
		priority_queue<int, vector<int>, greater<int>> q;
		for(int i = 1; i <= 1000; ++i){
			for(int x : adj[i]){
				q.push(x);
			}
			while(q.size() > i){
				q.pop();
			}
		}
		int res = 0;
		cout << q.size() << ' ';
		while(!q.empty()){
			res += q.top(); q.pop();
		}
		cout << res << '\n';
	}	

	return 0;
}


