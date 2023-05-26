
// created: 2023-05-26 18:28:52
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){	
		int n;
		cin >> n;
		vector<int> a(n);
		unordered_map<int, int> cnt;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			cnt[a[i]]++;
		}
		sort(a.begin(), a.end(), [&](int n1, int n2){
			if(cnt[n1] == cnt[n2])
				return n1 < n2;
			return cnt[n1] > cnt[n2];
		});
		for(int i : a)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}

