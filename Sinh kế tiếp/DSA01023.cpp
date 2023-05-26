
// created: 2023-05-26 17:31:35
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int a[100];
int b[100];

int n, k;
int cnt;
void Try(int i = 1){
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
		a[i] = j;
		if(i == k){
			bool flag = true;
			for(int l = 1; l <= k; ++l){
				if(a[l] != b[l])
					flag = false;
			}
			if(flag)
				cout << cnt << '\n';
			++cnt;
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
		cnt = 1;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n >> k;
		for(int i = 1; i <= k; ++i)
			cin >> b[i];
		Try();
	}
	return 0;
}


