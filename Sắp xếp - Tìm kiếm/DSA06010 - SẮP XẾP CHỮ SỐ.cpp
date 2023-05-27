
// created: 2023-05-26 18:26:47
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
		vector<string> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		set<char> st;
		for(string s: a){
			for(char c : s){
				st.insert(c);
			}
		}
		for(char c: st){
			cout << c << ' ';
		}
		cout << '\n';
	}	
    return 0;
}

