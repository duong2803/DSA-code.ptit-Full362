
// created: 2023-05-26 23:17:29
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;	
		cin >> n;
		deque<int> q;
		while(n--){
			int choice;
			cin >> choice;
			if(choice == 1){
				cout << q.size() << '\n';
			}else if(choice == 2){
				cout << (q.empty() ? "YES" : "NO") << '\n';
			}else if(choice == 3){
				int k;
				cin >> k;
				q.push_back(k);
			}else if(choice == 4){
				if(!q.empty()) q.pop_front();
			}else if(choice == 5){
				cout << (!q.empty() ? q.front() : -1) << '\n';
			}else if(choice == 6){
				cout << (!q.empty() ? q.back() : -1) << '\n';
			}
		}
	}	

	return 0;
}

