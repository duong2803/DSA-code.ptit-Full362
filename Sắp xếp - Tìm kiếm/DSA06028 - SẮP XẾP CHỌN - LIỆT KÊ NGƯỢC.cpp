
// created: 2023-05-26 18:30:48
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
		vector<vector<int>> res;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n - 1; ++i){
			int mn = i;
			for(int j = i + 1; j < n; ++j){
				if(a[j] < a[mn])
					swap(mn, j);
			}
			swap(a[i], a[mn]);
			res.push_back(a);
		}	
		for(int i = res.size() - 1; ~i; --i){
			cout << "Buoc " << i + 1 << ": ";
			for(int j : res[i])
				cout << j << ' ';
			cout << '\n';
		}

	return 0;
}

