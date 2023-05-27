
// created: 2023-05-26 17:46:50
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<vector<int>> res;

void Try(int s = n, vector<int> a = {}){

	if(s == 0){
		res.push_back(a);
		return;
	}	
	for(int i = s; i >= 1; --i){
		if(a.size() == 0){
			a.push_back(i);
			Try(s - i, a);
			a.pop_back();
		}else if(i <= a.back()){
			a.push_back(i);
			Try(s - i, a);
			a.pop_back();		
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
		cin >> n;
		Try();
		cout << res.size() << '\n';
		for(int i = 0; i < res.size(); ++i){
			cout << '(';
			for(int j = 0; j < res[i].size(); ++j){
				cout << res[i][j];
				if(j != res[i].size() - 1) cout << ' ';
			}
			cout << ") ";
		}
		cout << '\n';
	}
	return 0;
}

