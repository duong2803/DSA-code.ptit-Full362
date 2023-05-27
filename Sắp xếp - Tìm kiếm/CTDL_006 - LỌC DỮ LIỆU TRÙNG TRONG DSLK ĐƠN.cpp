
// created: 2023-05-26 18:24:19
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	int k;
	unordered_set<int> s;
	for(int i = 0 ;i < n; ++i){
		cin >> k;
		if(s.find(k) == s.end()){
			a.push_back(k);
		}
		s.insert(k);
	}
	for(int i : a)
		cout << i << ' ';
	return 0;
}

