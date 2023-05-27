
// created: 2023-05-26 18:31:03
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);


		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b;
		vector<vector<int>> res;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i){
			b.push_back(a[i]);
			sort(b.begin(), b.end());
			res.push_back(b);
		}	
		for(int i = res.size() - 1; ~i; --i){
			cout << "Buoc " << i << ": ";
			for(int j : res[i])
				cout << j << ' ';
			cout << '\n';
		}

	return 0;
}

