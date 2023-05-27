
// created: 2023-05-26 18:29:48
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
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n - 1; ++i){
			for(int j = i + 1; j < n; ++j){
				if(a[i] > a[j]){
					swap(a[i], a[j]);
				}
			}
			cout << "Buoc " << i + 1 << ": ";
			for(int i : a){
				cout << i << ' ';
			}
			cout << '\n';
		}	

	return 0;
}

