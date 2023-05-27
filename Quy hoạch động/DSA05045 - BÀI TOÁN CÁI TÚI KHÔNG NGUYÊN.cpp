
// created: 2023-05-26 18:23:05
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		double w;
		cin >> n >> w;
		vector<pair<double, double>> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i].first >> a[i].second;
		sort(a.begin(), a.end(), [](pair<double, double> p1, pair<double, double> p2){
			return p1.first / p1.second > p2.first / p2.second;
		});

		double res = 0;
		for(int i = 0; i < n; ++i){
			if(w <= a[i].second){
				res += a[i].first * w / a[i].second;
				break;
			}else{
				res += a[i].first;
				w -= a[i].second;
			}
		}
		cout << fixed << setprecision(2) << res << '\n';
	}

	return 0;
}

