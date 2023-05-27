
// created: 2023-05-26 17:41:54
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char c;
int k;
int a[100];
int n;

void backtrack(int i = 1){
	for(int j = a[i - 1]; j <= n; ++j){
		a[i] = j;
		if(i == k){
			for(int l = 1; l <= k; ++l){
				cout << (char) ('A' + a[l]);
			}
			cout << '\n';
		}else
			backtrack(i + 1);
			
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> k;
	n = c - 'A';
	backtrack();
	return 0;
}

