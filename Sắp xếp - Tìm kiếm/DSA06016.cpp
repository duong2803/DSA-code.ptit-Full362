
// created: 2023-05-26 18:28:17
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;
		vector<ll> a(n), b(m);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < m; ++i)
			cin >> b[i];
		cout << *max_element(a.begin(), a.end()) * *min_element(b.begin(), b.end()) << '\n';
	}
	
    return 0;
}

