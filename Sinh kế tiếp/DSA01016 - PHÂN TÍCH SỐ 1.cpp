
// created: 2023-05-26 17:36:07
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void Try(int n, vector<int> a = {}){
	
	if(n == 0){
		cout << '(';
		for(int i = 0; i < a.size(); ++i){
			cout << a[i];
			if(i != a.size() - 1)
				cout << ' ';
		}
		cout << ") ";
		return;
	}
	for(int i = n; i >= 1; --i){
		if(a.size() == 0 || i <= a.back()){
			a.push_back(i);
			Try(n - i, a);
			a.pop_back();
		}
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		Try(n);
		cout << '\n';	
	}	
}

