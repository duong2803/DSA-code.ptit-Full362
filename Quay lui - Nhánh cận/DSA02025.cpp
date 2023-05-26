
// created: 2023-05-26 17:44:49
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; ++i)
 		cin >> a[i];
   	vector<int> b(n);
	vector<vector<bool>> c(n, vector<bool>(26));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 26; ++j){
			if(binary_search(a[i].begin(), a[i].end(), j + 'A')){
				c[i][j] = true;
			}else
				c[i][j] = false;
		}
	}
	int f[30][30];
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			int cnt = 0;
			for(int k = 0; k < 26; ++k){
				if(c[i][k] && c[j][k])
					++cnt;
			}
			f[i][j] = f[j][i] = cnt;
		}	
	}
	iota(b.begin(), b.end(), 0);
	int res = INT_MAX;	
	do{
		int cnt = 0;
		for(int i = 0; i < n - 1; ++i){
			cnt += f[b[i]][b[i + 1]];
		}
		res = min(cnt, res);
	}while(next_permutation(b.begin(), b.end()));
    cout << res;	
	return 0;
}

