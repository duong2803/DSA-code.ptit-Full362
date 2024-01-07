
// created: 2023-05-26 17:32:19
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
void Try(int N = n, string s = "", int i = 0, int cnt1 = 1, int cnt2 = 0){
	if(i == n - 2){
		if(cnt2 < 3){
			cout << 8;
			cout << s;
			cout << 6;
			cout << '\n';
		}
		return;
	}
	if(cnt2 < 3)
		Try(N, s + "6", i + 1, 0, cnt2 + 1);
	if(cnt1 < 1)
		Try(N, s + "8", i + 1, cnt1 + 1, 0);

}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	Try();
	return 0;
}


