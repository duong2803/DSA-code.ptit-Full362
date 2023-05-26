
// created: 2023-05-26 23:19:04
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;
		int cnt = 0;
		queue<string> q;
		q.push("1");
		while(!q.empty()){
			string fr = q.front(); q.pop();

			if(stoll(fr) > n){
				break;
			}
			++cnt;
			q.push(fr + "0");
			q.push(fr + "1");
		}
		cout << cnt <<'\n';
	}
	return 0;
}


