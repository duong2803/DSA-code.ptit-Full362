
// created: 2023-05-26 17:32:00
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int a[100];
vector<string> b;
int n, k;
void Try(int i = 1){
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
		a[i] = j;
		if(i == k){
			for(int l = 1; l <= k; ++l){
				char tmp = a[l] + 'A' - 1;
				cout << tmp; 
			}
			cout << '\n';
		}else
			Try(i + 1);
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> n >> k;
		Try();
	}	
	return 0;
}


