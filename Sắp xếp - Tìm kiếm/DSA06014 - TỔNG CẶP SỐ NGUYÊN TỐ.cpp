
// created: 2023-05-26 18:27:35
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

bool isPrime(int n){
	if(n < 2) return false;
	if(n == 2 || n == 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(int i = 5; i * i <= n; i += 6){
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {	
		int n;
		cin >> n;	
		
		bool flag = true;
		for(int i = 2; i <= n / 2; ++i){
			if(isPrime(i)){
				if(isPrime(n - i)){
					flag = false;
					cout << i << ' ' << n - i;
					break;
				}
			}
		}
		if(flag)
			cout << -1;
		cout << '\n';
	}	
    return 0;
}

