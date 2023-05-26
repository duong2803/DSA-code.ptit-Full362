
// created: 2023-05-26 23:20:28
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
			for(int j = 0; j < m; ++j)
				cin >> a[i][j];
		}
		vector<vector<int>> visited(n, vector<int>(m, false));
		queue<pair<pair<int,int>,int>> q;
		q.push({{0,0}, 0});
		visited[0][0] = true;
		int res = -1;
		while(!q.empty()){
			pair<pair<int,int>,int> fr = q.front(); q.pop();
			int x = fr.first.first;
			int y = fr.first.second;
			if(x == n - 1 && y == m - 1){
				res = fr.second;
				break;
			}
			int x1 = x + a[x][y];
			int y1 = y + a[x][y];
			if(x1 < n && x1 != x && !visited[x1][y]){
				visited[x1][y] = true;
				q.push({{x1, y}, fr.second + 1});
			}
			if(y1 < m && y1 != y && !visited[x][y1]){
				visited[x][y1] = true;
				q.push({{x, y1}, fr.second + 1});
			}
		}
		cout << res << '\n';
	}	

	return 0;
}

