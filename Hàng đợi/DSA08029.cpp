
// created: 2023-05-26 23:22:22
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// 123456
// 413526
int l[6] = {3,0,2,4,1,5};
// 123456
// 152463
int r[6] = {0,4,1,3,5,2};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string s1 = "", s2 = "";
		for(int i = 0; i < 6; ++i){
			int tmp;
			cin >> tmp;
			s1 += tmp + '0';
		}
		
		for(int i = 0; i < 6; ++i){
			int tmp;
			cin >> tmp;
			s2 += tmp + '0';
		}
		queue<pair<string,int>> q;
		q.push({s1,0});
		while(!q.empty()){
			pair<string,int> top = q.front(); q.pop();
			if(top.first == s2){
				cout << top.second << '\n';
				break;
			}	
			string ss(6,'0');
			for(int i = 0; i < 6; ++i)
				ss[i] = top.first[l[i]]; 
			q.push({ss, top.second + 1});
			for(int i = 0; i < 6; ++i)
				ss[i] = top.first[r[i]];
			q.push({ss, top.second + 1});
		}
	}

	return 0;
}

