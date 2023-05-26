
// created: 2023-05-26 23:21:42
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a = {0};
	queue<string> q;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	while(!q.empty()){
		string front = q.front(); q.pop();
		if(front.size() == 6) break;
		a.push_back(stoi(front));	
		for(char c = '0'; c <= '5'; ++c){
			if(front.find(c) == -1){
				q.push(front + c);
			}
		}
	}
	int t;
	cin >> t;

	while(t--){
		int l, r;
		cin >> l >> r;
		int k1 = lower_bound(a.begin(), a.end(), l) - a.begin();
		int k2 = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;	
		cout << k2 - k1 + 1 << '\n';
	}	

	return 0;
}

