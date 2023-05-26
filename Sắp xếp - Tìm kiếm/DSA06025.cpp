
// created: 2023-05-26 18:30:12
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);


		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i){
			b.push_back(a[i]);
			sort(b.begin(), b.end());
			cout << "Buoc " << i << ": ";
			for(int i : b){
				cout << i << ' ';
			}
			cout << '\n';
		}	

	return 0;
}

