
// created: 2023-05-26 18:28:40
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
		int n;
		cin >> n;
		set<int> a;
		for(int i = 0; i < n; ++i){
			int tmp;
			cin >> tmp;
			a.insert(tmp);
		}	
		cout << *a.rbegin() - *a.begin() - a.size() + 1 << '\n';
	}
	
    return 0;
}

