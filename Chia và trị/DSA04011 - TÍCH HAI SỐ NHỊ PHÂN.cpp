
// created: 2023-05-26 18:07:50
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		string s1 ,s2;
		cin >> s1 >> s2;
		ll n1 = 0, n2 = 0;
		ll tmp = 1;
		for(int i = s1.length() - 1; ~i; --i){
			if(s1[i] == '1')
				n1 += tmp;
			tmp <<= 1;
		}
		tmp = 1;
		for(int i = s2.length() - 1; ~i; --i){
			if(s2[i] == '1')
				n2 += tmp;
			tmp <<= 1;
		}	
		cout << n1 * n2 << '\n';
	}	
}

