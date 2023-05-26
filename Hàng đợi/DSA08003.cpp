
// created: 2023-05-26 23:18:00
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
			
		if(choice == "PUSHFRONT"){
			int x;
			cin >> x;
			q.push_front(x);
		}else if(choice == "PRINTFRONT"){
			if(!q.empty())
				cout << q.front() << '\n';
			else
				cout << "NONE" << '\n';	
		}else if(choice == "POPFRONT"){
			if(!q.empty())
				q.pop_front();
		}else if(choice == "PUSHBACK"){
			int x;
			cin >> x;
			q.push_back(x);
		}else if(choice == "PRINTBACK"){
			if(!q.empty())
				cout << q.back() << '\n';
			else
				cout << "NONE" << '\n';
		}else if(choice == "POPBACK"){
			if(!q.empty())
				q.pop_back();
		}	
	}
	return 0;
}

