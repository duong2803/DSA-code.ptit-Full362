
// created: 2023-05-26 18:19:17
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<map<int,int>> dp(100001);

void upd(int idx, int x, int y){
	map<int,int>::iterator it = dp[idx].lower_bound(x);
	while(it != dp[idx].end()){
		if(it->second <= y)
			break;
		dp[idx].erase(it);	
		it = dp[idx].lower_bound(x);
	}
	dp[idx].insert({x,y});
}

bool check(int m, int x, int y){
	auto it = dp[m].lower_bound(x);	
	if(it == dp[m].begin()) return false;
	--it;
	return y > it->second;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int res = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		int l = 1;
		int r = res;
		int tmp = 0;
		while(l <= r){
			int m = l + r >> 1;
			if(check(m, x, y)){
				l = m + 1;
				tmp = max(m, tmp);
			}else
				r = m - 1;
		}
		upd(tmp + 1, x, y);
		res = max(res, tmp + 1);
	}
	cout << res;
	return 0;
}

