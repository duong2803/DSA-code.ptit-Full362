
// created: 2023-05-26 17:33:34
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int b[200];
int a[200];

int cnt = 0;
void Try(int i = 1){
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j){
		a[i] = j;
		if(i == k){
			vector<int> tmp;
			for(int l = 1; l <= k; ++l){
				tmp.push_back(b[a[l]]);
			}
			bool flag = true;
			for(int l = 0; l < k - 1; ++l){
				if(tmp[l] > tmp[l + 1]){
					flag = false;
				}
			}
			if(flag){

				++cnt;
			}
		}else
			Try(i + 1);
	}	
}

const ll mod = 1e9 + 7;
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

	memset(a, 0, sizeof(a));
	cin >> n >> k;	
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	Try();
	cout << cnt;	
	return 0;
}

