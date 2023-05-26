
// created: 2023-05-26 23:19:34
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<string> res;
void backtrack(string s = "", int i = 0){
	res.push_back(s);
	if(i == n){
		return;
	}
	backtrack(s + "6", i + 1);
	backtrack(s + "8", i + 1);

}	

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		res.resize(0);
		cin >> n;

		backtrack();
		sort(res.begin(), res.end(), [](string s1, string s2){
			if(s1.length() != s2.length()) return s1.length() > s2.length();
			return s1 > s2;
		});
		for(string i : res)	
			cout << i << ' ';
		cout << '\n';	
	}
	return 0;
}

