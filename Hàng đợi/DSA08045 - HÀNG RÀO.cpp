
// created: 2023-05-26 23:24:05
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2501;
int n, m;
vector<int> a,b;

int adj[mxN][mxN];
bool visited[mxN][mxN];
int mx;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void compress(vector<int> &arr){
	vector<pair<int,int>> tmp(arr.size());
	for(int i = 0; i < arr.size(); ++i){
		tmp[i] = {arr[i], i};
	}	
	sort(tmp.begin(), tmp.end());
	int nxt = 2;

	for(int i = 0; i < arr.size(); ++i){
		if(i > 0 && tmp[i].first != tmp[i - 1].first) nxt += 2;
		arr[tmp[i].second] = nxt;	
		mx = max(mx,nxt + 5);
	}
	
}

int bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x, y});
	int cnt = 0;
	visited[x][y] = true;
	while(!q.empty()){
		pair<int,int> fr = q.front(); q.pop();
		int x1 = fr.first;
		int y1 = fr.second;	
		if(adj[x1][y1] == -1){
			++cnt;
		}
		for(int i = 0; i < 4; ++i){
			int xx = x1 + dx[i];
			int yy = y1 + dy[i];
			if(xx >= 0 && yy >= 0 && xx < mx && yy < mx && !visited[xx][yy] && adj[xx][yy] != 1){
				visited[xx][yy] = true;
				q.push({xx, yy});
			}	
		}
	}
	return cnt;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(adj, 0, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cin >> n >> m;
		a.clear();
		b.clear();
		for(int i = 0; i < n; ++i){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			a.push_back(x1);
			a.push_back(x2);
			b.push_back(y1);
			b.push_back(y2);
		}
		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			a.push_back(x);
			b.push_back(y);
		}
		compress(a);
		compress(b);
		for(int i = 0; i < 2 * n; i += 2){
			int x1 = a[i];
			int x2 = a[i + 1];
			int y1 = b[i];
			int y2 = b[i + 1];
			if(x1 == x2){
				if(y1 > y2) swap(y1, y2);
				for(int y = y1;  y <= y2; ++y){
					adj[x1][y] = 1;
				}
			}else{
				if(x1 > x2) swap(x1, x2);
					for(int x = x1; x <= x2; ++x)
					adj[x][y1] = 1;
			}
		}		
		for(int i = 2 * n; i < a.size(); ++i){
			adj[a[i]][b[i]] = -1;
		}
		int res = 0;
		for(int i = 2 * n; i < a.size(); ++i){
			int x = a[i];
			int y = b[i];
			if(!visited[x][y]){
				res = max(res, bfs(x, y));
			}
		}	
		cout << res << '\n';	
	}

	return 0;
}
