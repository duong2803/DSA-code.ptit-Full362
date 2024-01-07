
// created: 2023-05-26 17:35:32
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, s;
int a[100];
int cnt = 0;
void Try(int i = 1){
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
		a[i] = j;
		if(i == k){
			int sum = 0;
			for(int x = 1; x <= k; ++x){
				sum += a[x];
			}
			if(sum == s)
				++cnt;
		}else
			Try(i + 1);
	}

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(true){
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0)
			return 0;
		else{
			cnt = 0;
			memset(a, 0, sizeof(a));
			Try();
			cout << cnt << '\n';
		}
	}
}

