
// created: 2023-05-26 23:38:00
// author: Nguyen Tung Duong

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

struct Edge{
    int u,v;  
    Edge(int u, int v){
        this->u = u;
        this->v = v;
    }
};

const int mxN = 1001;
vector<int> adj[mxN]; 
bool visited[mxN];
int V, E, U;
vector<Edge> mst;

void dfs(int u = U){
	visited[u] = true;	
	for(int v: adj[u]){
		if(!visited[v]){
			Edge e(u,v);
			mst.push_back(e);
			dfs(v);
		}
	}
}

void bfs(int u = U){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v: adj[u]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
				Edge e(u,v);
				mst.push_back(e);
			}
		}
	}
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

   	int t;
	cin >> t;

	while(t--){
		mst.clear();
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cin >> V >> E >> U;
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >>u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bfs();
		if(mst.size() < V - 1){
			cout << -1 << '\n';
		}else{
			for(int i = 0; i < V - 1; ++i){
				cout << mst[i].u << ' ' << mst[i].v << '\n';
			}
		}
	}


    return 0;
}

