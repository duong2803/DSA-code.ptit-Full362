
// created: 2023-05-26 17:26:55
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a;
void S(){
	
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n; 
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		next_permutation(a.begin(), a.end());
		for(int i : a)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}

