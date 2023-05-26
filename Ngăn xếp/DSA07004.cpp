
// created: 2023-05-26 18:36:54
// author: Nguyen Tung Duong


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 9999999999;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		int cnt = 0;
		int tmp = 0;
		for(int i = 0; i < n; ++i){
			if(tmp == 0){
				if(s[i] == ')'){
					++cnt;
					++tmp;
				}else{
					tmp++;
				}
				continue;
			}

			if(s[i] == '('){
				tmp++;
			}else{
				tmp--;
			}

		}
		cout << cnt + tmp / 2 << '\n';
	}

	return 0;
}

