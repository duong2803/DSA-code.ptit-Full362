
// created: 2023-05-26 23:26:06
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;

class Edge{
	public:
		int u, v;
};

const ll mod = 1e9 + 7;
int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n;	
	cin >> n;
	cin.ignore();

	vector<int> a[51];	
	for(int i = 1; i <= n; ++i){
		string s;
		getline(cin, s);
		stringstream ss(s);
		int tmp;
		while(ss >> tmp){
			a[i].push_back(tmp);

		}

	}

	for(int i = 1; i <= n; ++i){
		for(int j : a[i]){
			if(i < j){
				cout << i << ' ' << j << '\n';
			}
		}
	}

    return 0;

}

