
// created: 2023-05-26 17:26:31
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;
void S(){
	int i = k;
	while(a[i] == n - k + i && i >= 1)
		--i;
	if(i == 0){
		for(int i = 1; i <= k; ++i){
			a[i] = i;
		}
		return;
	}
	a[i]++;
	for(int j = i + 1; j <= k; ++j){
		a[j] = a[j - 1] + 1;
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		a.resize(k + 1);
		for(int i = 1; i <= k; ++i)
			cin >> a[i]; 
		S();
		for(int i = 1; i <= k; ++i)
			cout << a[i] << ' ';
		cout << '\n';

	}
	return 0;
}

