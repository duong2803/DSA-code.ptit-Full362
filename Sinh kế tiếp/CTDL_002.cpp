
// created: 2023-05-26 17:25:41
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> a;
int n, k;
int cnt = 0;
void backtrack(string s = "", int i = 0){
	if(i == n){
		int sm = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == '1'){
				sm += a[i];
			}
		}
		if(sm == k){
			for(int i = 0; i < n; ++i){
				if(s[i] == '1')
					cout << a[i] << ' ';
			}
			++cnt;
			cout << '\n';
		}
		return;
	}
	backtrack(s + "0", i + 1);
	backtrack(s + "1", i + 1);

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];	
	backtrack();
	cout << cnt;
	return 0;
}

