
// created: 2023-05-26 17:37:57
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
vector<int> b;

void backtrack(vector<int> a = b, int i = 0){

	if(i == n){
		return;
	}
	cout << '[';
	for(int j = 0; j < n - i; ++j){
		cout << a[j];
		if(i != n - j - 1)
			cout << ' ';
	}
	for(int j = 0; j < n - i; ++j){
		a[j] = a[j] + a[j + 1];
	}
	cout << ']';
	cout << '\n';
	backtrack(a, i + 1);
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> n;
		b.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		backtrack();
	}
	return 0;
}


