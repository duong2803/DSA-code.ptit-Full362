
// created: 2023-05-26 17:53:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		int l = 0, r = n - 1;
		while(l < r){
			if(a[l] > a[r]){
				int l1 = l;
				int r1 = r;
				while(l1 < r1){
					swap(a[l1++], a[r1--]);
				}
			}			
			l++;
			r--;

		}	
		bool flag = true;
		for(int i = 0; i < n - 1; ++i){
			if(a[i + 1] < a[i])
				flag = false;
		}
		cout << (flag ? "Yes" : "No") << '\n';
	}
	
	return 0;
}

