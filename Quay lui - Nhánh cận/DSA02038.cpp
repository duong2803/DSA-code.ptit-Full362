
// created: 2023-05-26 17:46:36
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;
vector<int> b;
void S(int i = 1){
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
		a[i] = j;
		if(i == k){
			for(int l = 1; l <= k; ++l){
				cout << b[a[l] - 1] << ' ' ;
			}
			cout << '\n';	
		}else
			S(i+1);
	}	
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		a.clear();
		b.clear();
		cin >> n >> k; 
		a.resize(k + 1);
		b.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		sort(b.begin(), b.end());
		S();
	}
	return 0;
}

