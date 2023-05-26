
// created: 2023-05-26 17:50:16
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int a[25][25];
int res;

void Try(int u, int dist = 0){	
	res = max(res, dist);
	for(int v = 0; v < n; ++v){
		if(a[u][v]){
			a[u][v] = 0;
			a[v][u] = 0;
			Try(v, dist + 1);
			a[v][u] = 1;
			a[u][v] = 1;	
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
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
		for(int i = 0; i < n; ++i){
			Try(i);
		}
		cout << res << '\n';
	}
	return 0;
}

