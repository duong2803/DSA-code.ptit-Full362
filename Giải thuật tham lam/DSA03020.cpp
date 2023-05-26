
// created: 2023-05-26 17:58:07
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


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
		vector<int> pos;
		for(int i = 0; i < n; ++i){
			if(s[i] == '[')
				pos.push_back(i);
		}
		int tmp = 0;
		int it = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == '[') {
				++tmp;
				++it;
			}
			else
				--tmp;
			
			if(tmp < 0){
				cnt += pos[it] - i;
				swap(s[i], s[pos[it]]);
				it++;
				tmp = 1;
			}	
		}
		cout << cnt << '\n';
	}

	return 0;
}

