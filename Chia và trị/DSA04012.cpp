
// created: 2023-05-26 18:08:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < m; ++i)
			cin >> b[i];
		vector<int> res(n + m);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				res[i + j] += a[i] * b[j];
			}
		}
		for(int i = 0; i < n + m - 1; ++i){
			cout << res[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

