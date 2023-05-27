
// created: 2023-05-26 23:39:18
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1001;

struct Edge{
	int u, v, w;
	Edge(int u, int v, int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

int V, E;
vector<Edge> edges;
int par[mxN];
int sz[mxN];

int Find(int x){
	if(x == par[x]) return x;	
	return par[x] = Find(par[x]);	
}

bool Union(int x, int y){
	
	x = Find(x);
	y = Find(y);
	
	if(x == y) return false;
	if(sz[x] < sz[y]) swap(x, y);
	par[y] = x;
	return true;	
}

void Kruskal(){
	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){
		return e1.w < e2.w;
	});

	int res = 0;

	for(Edge e: edges){
		if(Union(e.u, e.v)){
			res += e.w;
		}
	}
	cout << res;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		edges.clear();
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			Edge e(u,v,w);
			edges.push_back(e);
		}		
		for(int i = 1; i <= V; ++i){
			sz[i] = 1;
			par[i] = i;
		}
		Kruskal();
		cout << '\n';
	}

	return 0;
}

