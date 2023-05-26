
// created: 2023-05-26 18:34:13
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
		vector<ll> a(n);	
		ll res = LLONG_MAX;	
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			a[i] *= a[i];
		}	
		bool flag = false;
		sort(a.begin(), a.end(), greater<ll>());
		for(int i = 0; i < n - 2; ++i){
			
			int l = i + 1;
			int r = n - 1;
			
			while(l < r){
				if(a[l] + a[r] == a[i]){
					flag = true;
					break;
				}else if(a[l] + a[r] < a[i]){
					r--;
				}else{
					l++;
				}
			}
		}
		cout << (flag ? "YES" : "NO") << '\n';	
	}
	return 0;
}

