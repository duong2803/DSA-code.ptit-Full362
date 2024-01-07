
// created: 2023-05-26 17:30:08
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;

void Try(string s = "", int i = 0, bool flag = false){
	
	if(i == n - 2){
		cout << 'H';
		cout << s;
		cout << 'A';
		cout << '\n';
		return;
	}
	Try(s + "A", i + 1, true);
	if(flag)
		Try(s + "H", i + 1, false);

}

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
		cin >> n;
		Try();
	}
	return 0;
}


