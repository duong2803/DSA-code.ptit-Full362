
// created: 2023-05-26 17:48:19
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;
bool flag = false;

void Try(vector<int> tmp = {}, int sum = k){

	if(sum == 0){
		flag = true;
		cout << "[";
		for(int i = 0; i < tmp.size(); ++i){
			cout << tmp[i];
			if(i != tmp.size() - 1)
				cout << ' ';
		}
		cout << "]";
		return;
	}

	for(int i = 0; i < n; ++i){
		if(a[i] <= sum){
			if(tmp.size() == 0){
				tmp.push_back(a[i]);
				Try(tmp, sum - a[i]);
				tmp.pop_back();
			}else{
				if(a[i] >= tmp.back()){
					tmp.push_back(a[i]);
					Try(tmp, sum - a[i]);
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
		cin >> n >> k;
		a.clear();
		a.resize(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(),a.end());
		Try();
		if(!flag)
			cout << -1;
		cout << '\n';	
	}	

	return 0;
}

