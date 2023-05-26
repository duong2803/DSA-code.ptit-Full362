
// created: 2023-05-26 17:43:35
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[20][20];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string directions = "DLRU";
int visited[20][20];
bool flag = false;

void Try(string s = "", int x = 0, int y = 0){
	if(x == n - 1 && y == n - 1){
		flag = true;
		cout << s << ' ';
		return;
	}
	for(int i = 0; i < 4; ++i){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 && yy >= 0 && xx < n && yy < n && a[xx][yy] == 1 && visited[xx][yy] == 0){
			visited[xx][yy] = 1;
			Try(s + directions[i], xx, yy);
			visited[xx][yy] = 0;
		}
	}
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		memset(a, 0, sizeof(a));
		flag = false;
		for(int i = 0; i < 20; ++i){
			for(int j = 0; j < 20; ++j){
				visited[i][j] = 0;
			}
		}
		cin >> n;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				cin >> a[i][j];
		}
		if(a[0][0] == 0){
			cout << -1 << '\n';
			continue;
		}
		a[0][0] = 0;
		Try();
		if(!flag){
			cout << -1;
		}

		cout << '\n';
	}	
}

