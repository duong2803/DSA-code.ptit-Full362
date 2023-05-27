
// created: 2023-05-26 17:39:03
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n, k;
int a[100];
bool flag = false;

void backtrack(string s = "", int i = 0){

	if(i == n){
		int m = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == '1'){
				m += a[i];
			}
		}
		
		if(m == k){
			flag = true;
			cout << '[';
			vector<int> tmp;
			for(int i = 0; i < n; ++i){
				if(s[i] == '1'){
					tmp.push_back(a[i]);
				}
			}
			for(int i = 0; i < tmp.size(); ++i){
				cout << tmp[i];
				if(i != tmp.size() - 1)
					cout << ' ';
			}
			cout << "] ";
		}
		return;
	}
	backtrack(s + "1", i + 1);
	backtrack(s + "0", i + 1);

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
		flag = false;
		cin >> n >> k;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n);
		backtrack();
		if(!flag){
			cout << -1;
		}
		cout << '\n';
	}

	return 0;
}


