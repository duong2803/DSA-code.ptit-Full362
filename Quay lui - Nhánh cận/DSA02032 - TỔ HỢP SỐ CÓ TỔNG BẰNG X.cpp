
// created: 2023-05-26 17:45:26
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int a[25];

vector<vector<int>> res;

void Try(int sum = k, vector<int> tmp = {}){

	if(sum == 0){
		res.push_back(tmp);
		return;
	}

	for(int i = 0; i < n; ++i){
		if(a[i] <= sum){
			if(tmp.size() == 0){
				tmp.push_back(a[i]);
				Try(sum - a[i], tmp);
				tmp.pop_back();
			}else{
				if(a[i] >= tmp.back()){
					tmp.push_back(a[i]);
					Try(sum - a[i], tmp);
					tmp.pop_back();
				}
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
		res.clear();
		cin >> n >> k;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		Try();
		if(res.size() == 0){
			cout << -1 << '\n';
		}else{
			cout << res.size() << ' ';
			for(int i = 0; i < res.size(); ++i){
				cout << '{';
				for(int j = 0; j < res[i].size(); ++j){
					cout << res[i][j];
					if(j != res[i].size() - 1)
						cout << ' ';
				}
				cout << "} ";
			}
			cout << '\n';
		}
	}

	return 0;
}

