
// created: 2023-05-26 23:22:08
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> a(3);
		int sum = 0;
		for(int i = 0; i < n; ++i){
			int tmp; cin >> tmp;
			if(tmp % 3 == 0){
				a[0].push_back(tmp);
			}else if(tmp % 3 == 1){
				a[1].push_back(tmp);
			}else
				a[2].push_back(tmp);
			sum += tmp;
		}	
		sort(a[1].begin(), a[1].end(), greater<int>());
		sort(a[2].begin(), a[2].end(), greater<int>());
		if(sum % 3 == 1){
			if(a[1].size() == 0 && a[2].size() < 2){
				cout << -1 << '\n';
				continue;
			}
			if(a[1].size() > 0){
				a[1].pop_back();
			}else{
				a[2].pop_back();
				a[2].pop_back();
			}
		}else if(sum % 3 == 2){
			if(a[1].size() < 2 && a[2].size() == 0){
				cout << -1 << '\n';
				continue;
			}
			if(a[2].size() > 0){
				a[2].pop_back();
			}else{
				a[1].pop_back();
				a[1].pop_back();
			}
		}
		for(int i : a[1]){
			a[0].push_back(i);
		}
		for(int i: a[2]){
			a[0].push_back(i);
		}
		if(a[0].size() == 0){
			cout << - 1<< '\n';
			continue;
		}
		sort(a[0].begin(), a[0].end(), greater<int>());
		for(int i : a[0])
			cout << i;
		cout << '\n';
		
	}
	return 0;
}


