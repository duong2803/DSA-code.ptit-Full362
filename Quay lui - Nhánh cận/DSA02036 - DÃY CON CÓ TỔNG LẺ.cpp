
// created: 2023-05-26 17:45:57
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[30];
int n;

void Try(int i = 0, vector<int> tmp = {}){
	if(i == n){
		int sum = 0;
		for(int i = 0; i < tmp.size(); ++i){
			sum += tmp[i];
		}	
		if(sum & 1){
			for(int i = 0; i < tmp.size(); ++i){
				cout << tmp[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	Try(i + 1, tmp);
	tmp.push_back(a[i]);
	Try(i + 1, tmp);
	tmp.pop_back();
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t;
	cin >> t;

	while(t--){
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n, greater<int>());
		Try();
	}
	return 0;
}

