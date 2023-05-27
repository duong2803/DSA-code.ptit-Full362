
// created: 2023-05-26 17:48:05
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;

int S;
bool used[100];
bool flag = false;

void Try(int s = S, int cnt = 0){
	if(flag)
		return;
	if(cnt == k){
		flag = true;
		return;
	}

	for(int i = 0; i < n; ++i){
		if(flag)
			return;
		if(!used[i]){
			used[i] = true;
			if(a[i] <= s){
				if(a[i] == s){
					Try(s, cnt + 1);
				}else{
					Try(s - a[i], cnt);
				}
			}
			used[i] = false;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = false;
		memset(used, false, sizeof(used));
		cin >> n >> k;
		a.clear();
		a.resize(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		int sum = 0;
		for(int i = 0; i < n; ++i) sum += a[i];
		if(sum % k != 0){
			cout << 0;
		}else{
			S = sum / k;
			Try();
			if(flag)
				cout << 1;
			else
				cout << 0;
		}
		cout << '\n';
	}	

	return 0;
}

