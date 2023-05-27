
// created: 2023-05-26 18:32:33
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
		for(int i = 0; i < n; ++i)
			cin >> a[i];
			
		vector<int> b;
		bool check1 = true;
		bool check2 = true;
		bool check3 = true;
		for(int i = 0; i < n - 1; ++i){
			if(a[i] < a[i + 1]){
				b.push_back(1);
				check1 = false;
			}else if(a[i] > a[i + 1]){
				b.push_back(-1);
				check2 = false;
			}else{
				b.push_back(0);
				check3 = false;
			}
		}
		int res = 0;
		if(check3){
			if(check1 || check2){
				cout << n << '\n';
				continue;
			}
		}
		for(int i = 0; i < n - 2; ++i){
			if(b[i] == 1 && b[i + 1] == -1){
				int l = i;
				int r = i + 1;
				while(b[l] == 1 && l >= 0)
					--l;
				while(b[r] == -1 && r < n - 2)
					++r;
				if(b[l] != 1) ++l;
				if(b[r] != -1) --r;
				res = max(res, r - l + 2);
			}
		}	
		cout << res << '\n';
	}
	return 0;
}

