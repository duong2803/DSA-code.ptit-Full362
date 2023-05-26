
// created: 2023-05-26 17:45:45
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n, k;
	cin >> n >> k;
	vector<string> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	vector<int> b(k);
	iota(b.begin(), b.end(), 0);

	int res = INT_MAX;	
	do{
		vector<string> tmp(n);
		for(int i = 0; i < n; ++i){
			tmp[i] = a[i];
			for(int j = 0; j < k; ++j){
				tmp[i][j] = a[i][b[j]];
			}
		}
		string s1 = *min_element(tmp.begin(), tmp.end());
		string s2 = *max_element(tmp.begin(), tmp.end());
		res = min(res, stoi(s2) - stoi(s1));	
	}while(next_permutation(b.begin(), b.end()));
	cout << res;
	return 0;
}

