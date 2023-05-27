
// created: 2023-05-26 18:27:10
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

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

    while (t--)
    {		
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];	
		sort(a.begin(), a.end());
		for(int i = n - 1; i >= n - k; --i)
			cout << a[i] << ' ';
		cout << '\n';
	}	
    return 0;
}

