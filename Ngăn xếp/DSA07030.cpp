
// created: 2023-05-26 18:42:37
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

	while(t--){
		int n, m;
		cin >> n >> m;
	
		vector<vector<int>> mat(n, vector<int>(m));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> mat[i][j];
			}
		}
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(mat[i][j] != 0)
					mat[i][j] += mat[i - 1][j];
			}
		}
		int res = 0;
	
		for(int i = 0; i < n; ++i){
			stack<int> st;
			for(int j = 0; j < m; ++j){
				
				while(!st.empty() && mat[i][j] <= mat[i][st.top()]){
					int top = st.top(); st.pop();
					int l = st.empty() ? -1 : st.top();
				  	res = max(res, (j - l - 1) * mat[i][top]);	
				}
				st.push(j);	
			}
		}
		cout << res << '\n';
	}
	
    return 0;
}

