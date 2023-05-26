
// created: 2023-05-26 23:22:54
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<string> a;
int x1, _y1, x2, y2;
void bfs(){

	queue<pair<pair<int,int>,pair<int,int>>> q;
	for(int i = 0; i < 4; ++i){
		int x = x1 + dx[i];
		int y = _y1 + dy[i];
		if(x < n && y < n && x >= 0 && y >= 0 && a[x][y] == '.'){
			a[x][y] = 'X';
			q.push({{x, y}, {1, i}});
		}
	}
	a[x1][_y1] = 'X';
	while(!q.empty()){
		pair<pair<int,int>, pair<int,int>> fr = q.front(); q.pop();
		int x = fr.first.first;
		int y = fr.first.second;
		int step = fr.second.first;
		int dir = fr.second.second;
		if(x == x2 && y == y2){
			cout << step << '\n';
			return;
		}
		for(int i = 0; i < 4; ++i){
			int xx = x + dx[i];
			int yy = y + dy[i];
			while(xx >= 0 && yy >= 0 && xx < n && yy < n && a[xx][yy] == '.'){
				a[xx][yy] = 'X';
				q.push({{xx, yy}, {i == dir ? step : step + 1, i}});
				xx += dx[i];
				yy += dy[i];
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
		cin >> n;
		a.clear();
		a.resize(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		cin >> x1 >> _y1 >> x2 >> y2;
		if(x1 == x2 && _y1 == y2){
			cout << 0 << '\n';
		}else
			bfs();	
	}
	return 0;
}

