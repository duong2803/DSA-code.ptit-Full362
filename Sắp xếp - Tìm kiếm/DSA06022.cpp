
// created: 2023-05-26 18:29:31
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

		set<int> a;
		for(int i = 0; i < n; ++i){
			int tmp;
			cin >> tmp;
			a.insert(tmp);
		}
		if(a.size() == 1){
			cout << -1 << '\n';
		}else{
			int cnt = 0;
			for(int i : a){
				cout << i << ' ';
				++cnt;
				if(cnt == 2)
					break;
			}
		}
		cout << '\n';
	}
	return 0;
}

