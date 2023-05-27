
// created: 2023-05-26 17:57:33
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
		int n;
		cin >> n;
		string s = "";
		int k = n % 7;
		int cnt4 = 0, cnt7 = 0;
		int a[7] = {0,8,16,24,4,12,20};
		if(n < a[k]){
			cout << -1;
		}
		else{
			cnt4 += a[k] / 4;
			n -= a[k];
			cnt7 += n / 7;
			for(int i = 0; i < cnt4; ++i){
				cout << 4;
			}
			for(int i = 0; i < cnt7; ++i){
				cout << 7;
			}
		}		
		cout << '\n';
	}
	return 0;
}

