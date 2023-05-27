
// created: 2023-05-26 18:31:43
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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}		
		deque<int> q;
		for(int i = 0; i < k; ++i){
			while(!q.empty() && a[q.back()] <= a[i]){
				q.pop_back();
			}
			q.push_back(i);
		}
		cout << a[q.front()] << ' ';
		for(int i = k; i < n; ++i){
			if(i - q.front() == k){
				q.pop_front();
			}
			while(!q.empty() && a[q.back()] <= a[i]){
				q.pop_back();
			}
			q.push_back(i);
			cout << a[q.front()] << ' ';
		}
		cout << '\n';
	   		
	}
	return 0;
}

