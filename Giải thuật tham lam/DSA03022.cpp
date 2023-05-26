
// created: 2023-05-26 17:54:38
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;	
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	priority_queue<ll> q;
	cout << max(a[n - 1] * a[n - 2] * a[n - 3], max(a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2]));	
	return 0;
}

