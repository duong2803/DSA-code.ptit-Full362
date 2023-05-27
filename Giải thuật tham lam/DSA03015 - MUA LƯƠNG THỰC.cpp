
// created: 2023-05-26 17:54:26
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
		int a,b,c;
		cin >> a >> b >> c;
	
		int k = b / 7;
		int foods = b * c;
		int buys = a * (b - k);
		if(buys < foods){
			cout << -1;
		}else{
			int res = foods / a;
			if(foods % a != 0)
				++res;
			cout << res;
		}
		cout << '\n';
	}
	
	return 0;
}

