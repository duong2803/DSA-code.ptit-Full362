
// created: 2023-05-26 23:33:01
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

const int mxN = 20;
int V, E, M;

int a[mxN][mxN];
int color[mxN];

bool check(int u, int clr){
	for(int i = 1; i <= V; ++i){
		if(a[u][i] && clr == color[i]){
			return false;	
		}	
	}
	return true;
}

bool Try(int u = 1){
	
	if(u == V + 1) return true;	
	for(int clr = 1; clr <= M; ++clr){
		if(check(u, clr)){
			color[u] = clr;
			if(Try(u + 1)) return true;	
			color[u] = 0;
		}

	}
	return false;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		cin >> V >> E >> M;
		memset(a, 0, sizeof(a));
		memset(color, 0, sizeof(color));
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			a[u][v] = 1;	
			a[v][u] = 1;
		}		
		cout << (Try() ? "YES" : "NO") << '\n';	
	}
	return 0;
}


