
// created: 2023-05-26 23:23:07
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 , 0};

int n, m;
int a[501][501];
int res;

void bfs(){
	queue<pair<pair<int,int>, int>> q;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] == 2){
				q.push({{i,j}, 0});
			}
		}
	}
	while(!q.empty()){
		pair<pair<int,int>, int> fr = q.front(); q.pop();
		int x = fr.first.first;
		int y = fr.first.second;
		int step = fr.second;
		res = max(res, step);
		for(int i = 0; i < 4; ++i){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && yy >= 0 && xx < n && yy < m && a[xx][yy] == 1){
				a[xx][yy] = 2;
				q.push({{xx, yy}, step + 1});
			}	
		}	
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] == 1){
				res = -1;
				break;
			}
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		res = 0;
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> a[i][j];
			}
		}	
		bfs();		
		cout << res << '\n';
	}
	return 0;
}


