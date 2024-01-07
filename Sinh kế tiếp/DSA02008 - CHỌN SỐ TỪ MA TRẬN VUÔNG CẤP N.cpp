
// created: 2023-05-26 17:36:35
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int a[10][10];
bool visited[10];
vector<vector<int>> ans;

void Try(int row = 0, int sum = k, vector<int> res = {}){
		
	if(row == n){
		if(sum == 0){
			ans.push_back(res);
		}
		return;
	}	
	for(int i = 0; i < n; ++i){
		if(a[row][i] <= sum && !visited[i]){
			visited[i] = true;
			res.push_back(i + 1);
			Try(row + 1, sum - a[row][i], res);
		   	res.pop_back();	
			visited[i] = false;
		}	
	}

}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t = 1;
	//cin >> t;

	while(t--){
		memset(visited, false, sizeof(visited));
		cin >> n >> k;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				cin >> a[i][j];
		}	
		Try();
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); ++i){
			for(int j : ans[i]){
				cout << j << ' ';
			}
			cout << '\n';
		}
	}	
 	 
    return 0;
}

