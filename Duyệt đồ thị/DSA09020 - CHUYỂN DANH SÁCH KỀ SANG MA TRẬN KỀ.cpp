
// created: 2023-05-26 23:27:10
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1001;
const ll mod = 1e9 + 7;

bool visited[mxN];
vector<pair<int, int>> edges;
vector<int> adj[mxN];
void dfs(int s, int t, int u){
	visited[u] = true;
	for(int v: adj[u]){
		if(u == s && v == t || u == t && v == s) continue;
		if(!visited[v])
			dfs(s, t, v);
	}
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

  	int n;
	cin >> n;
	cin.ignore();
	int mat[mxN][mxN];
	memset(mat, 0, sizeof(mat));
	for(int i = 1; i <= n; ++i){
		string s;
		getline(cin, s);

		stringstream ss(s);
		int k;
		while(ss >> k){
			mat[i][k] = 1;
		}	
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	
    return 0;
}

