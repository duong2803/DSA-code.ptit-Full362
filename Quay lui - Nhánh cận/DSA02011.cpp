
// created: 2023-05-26 17:48:34
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;

int res;

void Try(int i = 0, int s = 0, int cnt = 0){
	
	if(cnt >= res) return;
	if(s == k){
		res = min(res, cnt);
		return;
	}
	if(i == n) return;
	if(s + a[i] <= k)
		Try(i + 1, s + a[i], cnt + 1);
	Try(i + 1, s, cnt);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		a.clear();	
		cin >> n >> k;
		a.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		res = n - 1;
		sort(a.begin(), a.end(), greater<int>());
		Try();	
		cout << (res == n - 1 ? -1 : res) << '\n';
	}
	return 0;
}

