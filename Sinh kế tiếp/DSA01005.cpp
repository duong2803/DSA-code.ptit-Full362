
// created: 2023-05-26 17:27:39
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;
void S(int i = 1){
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
		a[i] = j;
		if(i == k){
			for(int l = 1; l <= k; ++l){
				cout << a[l];
			}
			cout << ' ';
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
		cin >> n; 
		a.resize(n);
		for(int i = 0; i < n; ++i){
			a[i] = i + 1;
		}	
		do{
			for(int i : a){
				cout << i;
			}
			cout << ' ';
		}while(next_permutation(a.begin(), a.end()));
		cout << '\n';
	}
	return 0;
}

