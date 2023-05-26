
// created: 2023-05-26 18:11:48
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll C[1001][1001];

void cal(){
	C[0][0] = 1;
	for(int n = 1; n <= 1000; ++n){
		for(int k = 0; k <= n; ++k){
			if(k == 0)
				C[n][k] = 1;
			else{
				C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
				C[n][k] %= mod;
			}

		}
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cal();
	int t;
	cin >> t;

	while(t--){
		int n, k;
		cin >> n >> k;
		cout << C[n][k] << '\n';
	}

	return 0;
}

