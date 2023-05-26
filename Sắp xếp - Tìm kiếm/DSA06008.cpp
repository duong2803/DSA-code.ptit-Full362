
// created: 2023-05-26 18:26:20
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		vector<int> ex(5);
		for(int i = 0; i < m; ++i){
			cin >> b[i];
			if(b[i] >= 0 && b[i] <= 4)
				ex[b[i]]++;
		}
		sort(b.begin(), b.end());

		ll cnt = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] == 0)
				continue;
			if(a[i] == 1)
				cnt += ex[0];
			else{
				auto it = upper_bound(b.begin(), b.end(), a[i]);
				cnt += b.end() - it;
				cnt += ex[0] + ex[1];
				if(a[i] == 2)
					cnt -= (ex[3] + ex[4]);
				if(a[i] == 3)
					cnt += ex[2];
			}
		}
		cout << cnt << '\n';
		
	}	
    return 0;
}

