
// created: 2023-05-26 18:24:03
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
	for(int i = 0 ;i < n; ++i)
		cin >> a[i];
	int k;
	cin >> k;
	for(int i = 0; i < n; ++i){
		if(a[i] != k)
			cout << a[i] << ' ';
	}
	return 0;
}

