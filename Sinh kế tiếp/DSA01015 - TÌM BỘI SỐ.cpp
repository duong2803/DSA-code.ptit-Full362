
// created: 2023-05-26 17:35:47
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

	while(t--){
		int n;
		cin >> n;
		queue<ll> q;
		q.push(9);
		while(!q.empty()){
			ll front = q.front(); q.pop();
			if(front % n == 0){
				cout << front << '\n';
				break;
			}else{
				q.push(front * 10);
				q.push(front * 10 + 9);
			}
		}
	}	
}
