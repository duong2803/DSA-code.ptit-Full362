
// created: 2023-05-26 18:26:09
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
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		
		vector<int> b = a;
		sort(a.begin(), a.end());
		int l = 0, r= n- 1;
		while(a[l] == b[l]) ++l;
		while(a[r] == b[r]) --r;
		cout << l + 1<< ' ' << r + 1<< '\n';

	}	
    return 0;
}

