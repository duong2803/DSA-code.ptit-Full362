
// created: 2023-05-26 17:51:50
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	vector<int> a = {1,2,5,10,20,50,100,200,500,1000};
	while(t--){
		int n;
		cin >> n;
		int res = 0;
		int i = a.size() - 1;
		while(n > 0 && i >= 0){
			res += n / a[i];
			n %= a[i];
			--i;
		}
		cout << res << '\n';
		
	}
	return 0;
}
