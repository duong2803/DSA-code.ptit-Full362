
// created: 2023-05-26 18:38:15
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>> t;

	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		vector<string> a;
		while(ss >> tmp){
			a.push_back(tmp);
		}
		for(int i = a.size() - 1; ~i; --i){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}	
	
	return 0;
}


