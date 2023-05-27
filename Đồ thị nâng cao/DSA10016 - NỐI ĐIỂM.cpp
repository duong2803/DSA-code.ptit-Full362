
// created: 2023-05-26 23:39:44
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

class Point{
public:
	double x;
	double y;
};

class Edge{
public:

	int u;
	int v;
	double w;	
};

const int mxN = 1001;
int par[mxN];
int sz[mxN];
int n;
vector<Edge> E;
double dis(Point a, Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void init(){
	for(int i = 1; i <= n; ++i){
		par[i] = i;
		sz[i] = 1;
	}
}

int Find(int u){
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) 
		return false;
	if(sz[a] < sz[b]) 
		swap(a,b);
	par[b] = a;
	sz[a] += b;
	return true;
}

void mst(){
	init();
	sort(E.begin(), E.end(), [](Edge &e1, Edge &e2){
		return e1.w < e2.w;
	});	
	double d = 0;
	for(int i = 0; i < E.size(); ++i){
		if(Union(E[i].u, E[i].v)){
			d += E[i].w;
		}
	}
	cout << fixed << setprecision(6) << d << '\n';
}


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(par, 0, sizeof(par));
		memset(sz, 0, sizeof(sz));
		E.clear();
		cin >> n;
		vector<Point> a(n + 1);
		for(int i = 1; i <= n; ++i){
			cin >> a[i].x >> a[i].y;
		}	
		for(int i = 1; i <= n - 1; ++i){
			for(int j = i + 1; j <= n; ++j){
				Edge e;
				e.u = i;
				e.v = j;
				e.w = dis(a[i], a[j]);
				E.push_back(e);
			}
		}

		mst();
	}
	return 0;
}
