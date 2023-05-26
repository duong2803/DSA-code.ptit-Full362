
// created: 2023-05-26 18:08:37
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e5 + 5;
ll fen[mxN];

void compress(vector<int>& a){
	int n = a.size();
	vector<pair<int, int>> pairs(n);
	for(int i = 0; i < n; ++i) {
		pairs[i] = {a[i], i};
	}
	sort(pairs.begin(), pairs.end());
	int nxt = 1;
	for(int i = 0; i < n; ++i) {
		if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
		a[pairs[i].second] = nxt;		
	}	
}

void upd(int i){
	for(; i < mxN; i += i & -i) fen[i]++;
}

ll qry(int i){
	ll res = 0;
	for(;i > 0; i -= i & -i) res += fen[i];
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		memset(fen, 0, sizeof(fen));
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		compress(a);
		ll cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			cnt += qry(a[i] - 1);
			upd(a[i]);
		}
		cout << cnt << '\n';
		
	}
	return 0;
}
