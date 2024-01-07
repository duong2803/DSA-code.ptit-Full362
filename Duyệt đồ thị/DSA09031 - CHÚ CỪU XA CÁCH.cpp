
// created: 2023-05-26 23:35:21
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, m;

const int mxN = 101;

set<pair<pair<ll,ll>, pair<ll,ll>>> ok;
bool visited[mxN][mxN];
ll a[mxN][mxN];
vector<pair<ll,ll>> p;
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};

ll bfs(pair<ll,ll> p1){
	ll res = 0;	
	queue<pair<ll,ll>> q;
	q.push(p1);
	visited[p1.first][p1.second] = true;
	while(!q.empty()){
		pair<ll,ll> fr = q.front(); q.pop();
		ll x = fr.first;
		ll y = fr.second;

		res += a[x][y];
		for(ll i = 0; i < 4; ++i){
			ll xx = x + dx[i];
			ll yy = y + dy[i];
			pair<ll,ll> tmp = {xx, yy};
			if(xx <= n && yy <= n && xx >= 1 && yy >= 1 && !visited[xx][yy] && ok.find({fr, tmp}) == ok.end()){
				visited[xx][yy] = true;
				q.push({xx,yy});
			}
		}
	}
	return res * (res - 1) / 2;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(a, 0, sizeof(a));	
	memset(visited, false, sizeof(visited));	
	cin >> n >> k >> m;
	for(ll i = 0; i < m; ++i){
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ok.insert({{x1,y1}, {x2, y2}});
		ok.insert({{x2, y2}, {x1, y1}});
	}
	for(ll i = 0; i < k; ++i){
		ll x, y;
		cin >> x >> y;		
		p.push_back({x,y});
		a[x][y]++;
	}
	ll cnt = k * (k - 1) / 2;
	for(ll i = 0; i < k; ++i){
		if(!visited[p[i].first][p[i].second]){
			cnt -= bfs(p[i]);
		};
	}
	cout << cnt;
	return 0;
}


