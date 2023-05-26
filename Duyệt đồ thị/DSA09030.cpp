
// created: 2023-05-26 23:33:57
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
vector<int> adj[mxN];
int V, E, n;
bool flag;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		memset(adj, {}, sizeof(adj));
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}		
		vector<int> side(V + 1, -1);
		queue<int> q;
		flag = true;
		for(int i = 1; i <= V; ++i){
			if(side[i] == -1){
				side[i] = 0;
				q.push(i);
				while(!q.empty()){
					int u = q.front(); q.pop();
					for(int v: adj[u]){
						if(side[v] == -1){
							side[v] = side[u] ^ 1;
							q.push(v);
						}else{
							flag &= (side[v] ^ side[u]);
						}
					}
				}
			}
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}

