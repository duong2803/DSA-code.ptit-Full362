
// created: 2023-05-26 18:10:51
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
	
	vector<int> res;
	res.push_back(a[0]);
	for(int i = 1; i < n; ++i){
		if(res.back() < a[i]){
			res.push_back(a[i]);
		}else{
			int l = 0;
			int r = res.size() - 1;
			int idx = r;
			while(l <= r){
				int m = l + r >> 1;
				if(res[m] >= a[i]){
					idx = m;
					r = m - 1;
				}else
					l = m + 1;
			}
			res[idx] = a[i];
		}
	}
	cout << res.size() << '\n';

	return 0;	
}

