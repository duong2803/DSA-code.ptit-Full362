
// created: 2023-05-26 17:49:42
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, n, m;
set<string> s;

bool visited[10][10];
char a[10][10];
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
vector<string> res;

void Try(int x, int y, string S){
	if(s.find(S) != s.end()) res.push_back(S);	
	for(int i = 0; i < 8; ++i){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy]){
			visited[xx][yy] = true;
			Try(xx, yy, S + a[xx][yy]);
			visited[xx][yy] = false;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){

		res.clear();
		s.clear();
		cin >> k >> n >> m;
		for(int i = 0; i < k; ++i){
			string tmp;
			cin >> tmp;
			s.insert(tmp);
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j)
				cin >> a[i][j];
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				memset(visited, false, sizeof(visited));
				visited[i][j] = true;
				Try(i, j, string(1,a[i][j]));
			}
		}
		if(res.size() == 0){
			cout << -1;
		}else{
			for(string i : res) cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
