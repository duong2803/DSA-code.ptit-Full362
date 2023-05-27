
// created: 2023-05-26 18:26:59
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
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n ;++i)
			cin >> a[i];

		int res = INT_MAX;
		int m = INT_MAX;
		for(int i = 0; i < n - 1; ++i){
			for(int j = i + 1; j < n; ++j){
				if(abs(a[i] + a[j]) < m){
					res = a[i] + a[j];
					m = abs(a[i] + a[j]);
				}
			}
		}
		cout << res << '\n';
	}	
    return 0;
}

