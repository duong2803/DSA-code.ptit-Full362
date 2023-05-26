
// created: 2023-05-26 23:21:54
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<bool> sieve(10000, true);
	for(int i = 2; i * i <= 10000; ++i){
		if(sieve[i]){
			for(int j = i * i; j <= 10000; j += i){
				sieve[j] = false;
			}
		}
	}

	int t;
	cin >> t;

	while(t--){
		string s1, s2;
		cin >> s1 >> s2;
		queue<pair<string,int>> q;
		q.push({s1, 0});
		bool flag = false;
		set<string> visited;
		visited.insert(s1);
		while(!q.empty()){
			if(flag)
				break;
			pair<string,int> front = q.front(); q.pop();
			string x = front.first;
			int y = front.second;

			if(x == s2){
				cout << y << '\n';
				break;	
			}
			for(int i = 0; i < 4; ++i){
				for(char c = '0'; c <= '9'; ++c){
					if(i == 0 && c == '0') continue;
					if(c != x[i]){
						string tmp = x;
						tmp[i] = c;
						if(visited.find(tmp) == visited.end() && sieve[stoi(tmp)]){
							visited.insert(tmp);
							q.push({tmp, y + 1});
							if(tmp == s2){
								cout << y + 1 << '\n';
								flag = true;
							}
						}
					}
				}
			}	
		}	
	}	

	return 0;
}

