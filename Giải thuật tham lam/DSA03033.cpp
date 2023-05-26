
// created: 2023-05-26 17:59:41
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

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
		ll n, c;
		cin >> n >> c;
		if(n % 1000 != 0){
			cout << 0;
		}else{
			ll cnt = 0;
			ll ex = 1;
			n /= 1000;
			ll tmp = n;
			ll c1 = c;
			while(tmp > 0){
				ll k = tmp % 10;
				if(c1 < 0){
					break;
				}
				if(k == 1 || k == 2 || k == 3 || k == 5){
					++cnt;
				}else if(k == 4 || k == 6 || k == 7 || k == 8){
					cnt += 2;
				}else if(k == 9){
					cnt += 3;
				}
				tmp /= 10;
				c1--;
			}	
			cnt += (tmp << 1);
			while(n > 0){
				if(c == 0)
					break;
				ll e = n % 10;
				if(e == 4 || e == 6)
					ex <<= 1;
				else if(e == 9)
					ex *= 3;
				n /= 10;
				c--;
			}
			if(n < 10){
				if(n == 4 || n == 6)
					ex <<= 1;
				else if(n == 9)
					ex *= 3;
			}else{
				if(n % 5 == 1)
					ex <<= 1;
				else if(n % 5 == 4)
					ex *= 3;
			}
			cout << cnt << ' ' << ex;
		}
		cout << '\n';
	}
	return 0;
}

