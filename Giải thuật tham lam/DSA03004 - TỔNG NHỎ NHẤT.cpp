
// created: 2023-05-26 17:52:38
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
		vector<int> a;
		int tmp;
		for(int i = 0; i < n; ++i){
			cin >> tmp;
			if(tmp != 0)
				a.push_back(tmp);
		}
		sort(a.begin(), a.end());
		string s1, s2;
		ll i1 = 0, i2 = 1;
		while(i1 < a.size() && i2 < a.size()){
			s1 += to_string(a[i1]);
			s2 += to_string(a[i2]);
			i1+=2;
			i2+=2;
		}
		if(i1 == a.size() - 1) s1 += to_string(a[i1]);
		ll k1,k2;
		if(s1.length() == 0)
			k1 = 0;
		else
			k1 = stoll(s1);
		if(s2.length() == 0)
			k2 = 0;
		else 
			k2 = stoll(s2);
		cout << k1 + k2 << '\n';
	}

	return 0;
}

