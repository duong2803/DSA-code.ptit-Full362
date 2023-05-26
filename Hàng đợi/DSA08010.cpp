
// created: 2023-05-26 23:21:27
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
		int n;
		cin >> n;

		unordered_set<int> visited;	
		visited.insert(n);

		queue<pair<int,int>> q;
		q.push({n, 0});
		while(!q.empty()){
			pair<int,int> front = q.front(); q.pop();
			int x = front.first;
			int y = front.second;
			if(x == 1){
				cout << y << '\n';
				break;
			}
			if(x - 1 == 1){
				cout << y + 1 << '\n';
				break;
			}
			if(visited.find(x - 1) == visited.end()){
				q.push({x - 1, y + 1});
				visited.insert(x - 1);
			}
			
			for(int i = 2; i * i <= x; ++i){
				if(x % i == 0){
					if(visited.find(x / i) == visited.end()){
						q.push({x / i, y + 1});
						visited.insert(x / i);
						if(x / i == 1){
							cout << y + 1 << '\n';
							break;
						}
					}
				}
			}
		}
	}	

	return 0;
}

