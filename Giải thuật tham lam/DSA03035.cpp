
// created: 2023-05-26 17:55:47
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int tmp;
	unordered_map<int,int> mp;
	for(int i = 1; i <= n; ++i){
		cin >> tmp;
		mp[tmp] = i;
	}
	
	vector<int> b(n + 1);
	for(int i = 1; i <= n; ++i){
		b[i] = mp[i];
	}
	int m = 1;
	int msf = 1;
	for(int i = 2; i <= n; ++i){
		if(b[i] < b[i - 1]){
			m = 1;
		}else{
			m++;
		}
		msf = max(msf, m);
		
	}
	cout << n - msf;
	return 0;
}

