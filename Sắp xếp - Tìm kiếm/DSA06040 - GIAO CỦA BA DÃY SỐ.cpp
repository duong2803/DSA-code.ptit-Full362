
// created: 2023-05-26 18:33:20
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
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		int x = 0;
		int y = 0;
		int z = 0;	

		vector<ll> a1(n1), a2(n2), a3(n3);
		for(int i = 0; i < n1; ++i)
			cin >> a1[i];
		for(int i = 0; i < n2; ++i)
			cin >> a2[i];
		for(int i = 0; i < n3; ++i)
			cin >> a3[i];
		vector<ll> res;
		while(x < n1 && y < n2 && z < n3){
			if(a1[x] == a2[y] && a2[y] == a3[z]){
				res.push_back(a1[x]);
				x++;
				y++;
				z++;
			}else if(a1[x] < a2[y]){
				x++;
			}else if(a2[y] < a3[z]){
				y++;
			}else
				z++;
		}
		if(res.size() == 0)
			cout << -1;
		else{
			for(ll i : res)
				cout << i << ' ';
		}	
		cout << '\n';
	}
	return 0;
}

