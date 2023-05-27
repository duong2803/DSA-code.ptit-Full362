
// created: 2023-05-26 23:19:20
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
		queue<string> q;
		q.push("1");
		while(!q.empty()){
			string fr = q.front(); q.pop();

			if(stoll(fr) % n == 0){
				cout << fr;
				break;
			}
			q.push(fr + "0");
			q.push(fr + "1");
		}
		cout <<'\n';
	}
	return 0;
}


