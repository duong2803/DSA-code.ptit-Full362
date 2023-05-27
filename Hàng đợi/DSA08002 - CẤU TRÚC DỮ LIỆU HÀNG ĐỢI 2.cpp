
// created: 2023-05-26 23:17:47
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

	deque<int> q;
	while(t--){
		string choice;
		cin >> choice;
		if(choice == "PUSH"){
			int x;
			cin >> x;
			q.push_back(x);	
		}else if(choice == "PRINTFRONT"){
			if(!q.empty()){
				cout << q.front() << '\n';
			}else
				cout << "NONE" << '\n';
		}else if(choice == "POP"){
			if(!q.empty()) q.pop_front();
		}
	}
	return 0;
}

