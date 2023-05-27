
// created: 2023-05-26 17:58:24
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int > a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	int res = 0;
	int k = *min_element(a.begin(), a.end());
	for(int i = k;;--i){
		int tmp = 0;
		for(int j = 0; j < n; ++j){
			bool flag = false;
			for(int x = 1; x <= a[j]; ++x){
				if(a[j] / x == i){
					flag = true;
					tmp += x;
					break;
				}
			}
			if(!flag){
				tmp = 0;
				break;
			}
		}
		if(tmp != 0){
			res = tmp;
			break;
		}
	}
	cout << res;

	return 0;
}

