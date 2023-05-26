
// created: 2023-05-26 18:17:01
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
		vector<vector<int>> a(n, vector<int>(m));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> a[i][j];
			}
		}
		for(int i = m - 2; ~i; --i){
			a[n - 1][i] += a[n - 1][i + 1];
		}

		for(int i = n - 2; ~i; --i){
			a[i][m - 1] += a[i + 1][m - 1];
		}

		for(int i = n - 2; ~i; --i){
			for(int j = m - 2; ~j; --j){
				a[i][j] += min(a[i + 1][j + 1], min(a[i + 1][j], a[i][j + 1]));
			}
		}

		cout << a[0][0] << '\n';
	}

	return 0;
}

