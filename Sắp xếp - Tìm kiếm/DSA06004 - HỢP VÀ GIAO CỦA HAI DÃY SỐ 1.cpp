
// created: 2023-05-26 18:25:29
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
		vector<int> a(n);
		vector<int> b(m);
	
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < m; ++i)
			cin >> b[i];
	
		set<int> s1;
		set<int> s2;
		for(int i = 0; i < n; ++i){
			s1.insert(a[i]);
			s2.insert(a[i]);
		}
		for(int i = 0; i < m; ++i){
			s1.insert(b[i]);
		}
		for(int i : s1){
			cout << i << ' ';
		}
		cout << '\n';
		for(int i : b){
			if(s2.find(i) != s2.end())
				cout << i << ' ';
		}
		cout << '\n';
	}	
    return 0;
}

