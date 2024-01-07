
// created: 2023-05-26 17:36:49
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, k;
int a[1001];

void solve(){
	int i = k;
	while(a[i] - a[i - 1] == 1) --i;
	a[i]--;
	for(int j = i + 1; j <= k; ++j){
		a[j] = n - k + j;
	}
	for(int j = 1; j <= k; ++j)
		cout << a[j] << ' ';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(a, 0, sizeof(a));
		cin >> n >> k;
		for(int i = 1; i <= k; ++i) cin >> a[i];	
		solve();
		cout << '\n';	
	}

	return 0;
}

