
// created: 2023-05-26 23:33:44
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 501;
int a[mxN][mxN];
bool visited[mxN];
int V, E;
bool flag = false;

void Try(int j = 0, vector<int> x = {}){
	if(j == V){
		flag = true;
		return;
	}	
	for(int i =	1; i <= 10; ++i){
		if(flag) return;
		if(x.size() == 0){
			x.push_back(i);
			visited[i] = true;
			Try(j + 1, x);
			visited[i] = false;
			x.pop_back();
		}else if(!visited[i] && a[x.back()][i]){
			visited[i] = true;
			x.push_back(i);
			Try(j + 1, x);
			visited[i] = false;
			x.pop_back();
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = false;
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		cin >> V >> E;
		for(int i = 0; i < E; ++i){
			int u, v;
			cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
		}	
		Try();
		cout << (flag ? 1 : 0) << '\n';
	}

	return 0;
}

