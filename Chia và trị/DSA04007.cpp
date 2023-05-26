
// created: 2023-05-26 18:07:11
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
	
		int k;
		cin >> k;
		string a,b;
		cin >> a >> b;
		vector<int> n1, n2;
		for(int i = 0; i < a.length(); ++i){
			n1.push_back(a[i] - '0');
		}	
		for(int j = 0; j < b.length(); ++j){
			n2.push_back(b[j] - '0');
		}
		int k1 = n1.size() - 1;
		int k2 = n2.size() - 1;
		int mem = 0;
		vector<int> res;
		while(k1 >= 0 && k2 >= 0){
			int tmp = n1[k1--] + n2[k2--] + mem;
			if(tmp >= k){
				mem = 1;
				tmp %= k;
			}else
				mem = 0;
			res.push_back(tmp);
		}

		while(k1 >= 0){
			int tmp = n1[k1--] + mem;
			if(tmp >= k){
				mem = 1;
				tmp %= k;
			}else
				mem = 0;
			res.push_back(tmp);
		}
		while(k2 >= 0){
			int tmp = n2[k2--] + mem;
			if(tmp >= k){
				mem = 1;
				tmp %= k;
			}else
				mem = 0;
			res.push_back(tmp);
		}
		if(mem == 1)
			res.push_back(1);
		for(int i = res.size() - 1; i >= 0; --i){
			cout << res[i];
		}
		cout << '\n';
	}
	
    return 0;
}

