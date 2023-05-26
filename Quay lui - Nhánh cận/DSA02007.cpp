
// created: 2023-05-26 17:43:52
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string res;
int n;

void Try(string s, int k){
	
	if(k == 0){
		res = max(s, res);
		return;
	}
	for(int i = 0; i < n - 1; ++i){
		char mx = s[i];
		for(int j = i + 1; j < n; ++j){
			mx = max(mx, s[j]);
		}
		if(mx != s[i]){
			for(int j = i + 1; j < n; ++j){
				if(s[j] == mx){
					swap(s[i], s[j]);
					Try(s, k - 1);
					swap(s[i], s[j]);
				}
			}
		}
	}
	res = max(s, res);
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t;
	cin >> t;

	while(t--){
		int k;
		cin >> k;
		string s;
		cin >> s;
		res = s;
		n = s.length();
		Try(s, k);
		cout << res <<'\n';
	}	
 	 
    return 0;
}

