
// created: 2023-05-26 23:20:55
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		int S, T;
		cin >> S >> T;

		queue<pair<int,int>> q;
		q.push({S, 0});

		bool visited[1 << 19];
		memset(visited, false, sizeof(visited));

		while(!q.empty()){
			pair<int,int> fr = q.front(); q.pop();
			visited[fr.first] = true;
			if(fr.first == T){
				cout << fr.second << '\n';
				break;
			}
			if(!visited[fr.first * 2])
			if(fr.first * 2 <= 100000)
			q.push({fr.first * 2, fr.second + 1});
			if(!visited[fr.first - 1])
			if(fr.first != 0)
				q.push({fr.first - 1, fr.second + 1});
			
		}
			
	}
	
    return 0;
}

