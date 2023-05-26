
// created: 2023-05-26 18:35:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<int> a;
const int mxN = 1e5 + 5;

ll bit[mxN];

void upd(int i){
	for(;i < mxN; i += i & -i) ++bit[i];
}

ll qry(int i){
	ll res = 0;
	for(;i > 0; i -= i & -i) res += bit[i];
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(bit, 0, sizeof(bit));
	
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	ll res = 0;	
	int last = n;
	for(int i = n - 1; ~i; --i){
		if(a[i] & 1){
			for(int j = i + 1; j < last; ++j)
				upd(a[j]);
			last = i; 
		}
		else
			res += qry(a[i] - 1);
	}	
	cout << res;

	return 0;
}

