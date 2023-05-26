
// created: 2023-05-26 23:29:26
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
const ll mod = 1e9 + 7;
const int mxN = 1001;
vector<int> adj[1001];
int V, E;
int indeg[mxN];
int outdeg[mxN];
void solve(){
	for(int i = 1; i <= V; ++i){
		outdeg[i] = adj[i].size();
		for(int v : adj[i]){
			indeg[v]++;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= V; ++i){
		if(indeg[i] == outdeg[i])
			++cnt;
	}	
	if(cnt == V){
		cout << 1 << '\n';
	}else
		cout << 0 << '\n';
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
		memset(outdeg, 0, sizeof(outdeg));
		memset(indeg, 0, sizeof(indeg));
		memset(adj, {}, sizeof(adj));
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		solve();
	}	
	return 0;
}

