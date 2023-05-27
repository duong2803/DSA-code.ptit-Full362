
// created: 2023-05-26 17:38:26
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
int a[100][100];
bool flag = false;

void backtrack(string s = "", int x = 0, int y = 0){
	
	if(x == n || y == n) return;
	if(a[x][y] == 0) return;
	if(x == n - 1 && y == n - 1){
		cout << s << ' ';
		flag = true;
		return;
	}
	backtrack(s + "D", x + 1, y);
	backtrack(s + "R", x, y + 1);
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
		flag= false;
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				cin >> a[i][j];
		}
		backtrack();
		if(!flag)
			cout << -1;
		cout << '\n';
	}
	return 0;
}


