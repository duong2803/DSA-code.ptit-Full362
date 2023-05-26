
// created: 2023-05-26 17:47:24
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
vector<string> res;
void Try(int i = 0, string tmp = ""){

	if(i == n){
		res.push_back(tmp);	
		return;
	}

	Try(i + 1, tmp);
	Try(i + 1, tmp + s[i]);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		res.clear();
		cin >> n >>  s;
		Try();
		sort(res.begin(), res.end());
		for(string i : res){
			cout << i  << ' ';
		}
		cout << '\n';
	}	

	return 0;
}

