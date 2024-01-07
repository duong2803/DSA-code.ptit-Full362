
// created: 2023-05-26 23:25:52
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;

class Edge{
	public:
		int u, v;
};

const ll mod = 1e9 + 7;
int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
		int V, E;
		cin >> V >> E;
		
		vector<Edge> edges(E);

		for(int i = 0; i < E; ++i){
			cin >> edges[i].u >> edges[i].v;
		}
		vector<int> adj[mxN];
		for(Edge e : edges){
			adj[e.u].push_back(e.v);
			adj[e.v].push_back(e.u);
		}
		int cnt = 1;
		for(int i = 1; i <= V; ++i){
			cout << cnt++ << ": ";
			for(int v : adj[i]){
				cout << v << ' ';
			}
			cout << '\n';
		}
	}	
    return 0;
}

