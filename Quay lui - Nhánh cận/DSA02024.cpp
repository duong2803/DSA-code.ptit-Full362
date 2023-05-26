
// created: 2023-05-26 17:40:39
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<string> res;

void backtrack(string s = "", int i = 0){
	if(i == n){
		vector<int> tmp;
		for(int j = 0; j < n; ++j){
			if(s[j] == '1'){
				tmp.push_back(a[j]);
			}
		}
		if(tmp.size() >= 2){
			bool flag = true;
			for(int j = 0; j < tmp.size() - 1; ++j){
				if(tmp[j] > tmp[j + 1])
					flag = false;
			}
			if(flag){
				string k = "";
				for(int j : tmp){
					k += to_string(j) + " ";
				}
				res.push_back(k);
			}
		}
		return;
	}
	backtrack(s + "1", i + 1);
	backtrack(s + "0", i + 1);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	a.resize(n);

	for(int i = 0; i < n ;++i)
		cin >> a[i];
	
	backtrack();
	sort(res.begin(), res.end());
	for(string s: res){
		cout << s << '\n';
	}
	return 0;

}

