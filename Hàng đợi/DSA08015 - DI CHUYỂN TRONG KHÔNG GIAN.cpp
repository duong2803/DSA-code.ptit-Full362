
// created: 2023-05-26 23:23:20
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int A, B, C;
char a[31][31][31];
vector<int> S;
vector<int> E;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs(){
	queue<pair<vector<int>,int>> q;	
	q.push({S, 0});
	while(!q.empty()){
		pair<vector<int>, int> fr = q.front(); q.pop();
		int x = fr.first[0];
		int y = fr.first[1];
		int z = fr.first[2];
		int step = fr.second;
		if(x == E[0] && y == E[1] && z == E[2]){
			cout << step << '\n';
			return;
		}
		for(int i = 0; i < 6; ++i){
			int xx = x + dx[i];
			int yy = y + dy[i];
			int zz = z + dz[i];
			if(xx < A && yy < B && zz < C && xx >= 0 && yy >= 0 && zz >= 0 && a[xx][yy][zz] == '.'){	
				a[xx][yy][zz] = '#';
				q.push({{xx, yy, zz}, step + 1});
			}
		}
	}	
	cout << -1 << '\n';
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> A >> B >> C;
		for(int i = 0; i < A; ++i){
			for(int j = 0; j < B; ++j){
				for(int k = 0; k < C; ++k){
					cin >> a[i][j][k];
					if(a[i][j][k] == 'S'){
						S = {i,j,k};
						a[i][j][k] = '#';
					}else if(a[i][j][k] == 'E'){
						E = {i, j, k};
						a[i][j][k] = '.';
					}
				}
			}
		}
		bfs();		
	}
	return 0;
}


