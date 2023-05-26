
// created: 2023-05-26 17:33:16
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a;
vector<int> c;

int n, w;
int fopt;
string xopt;
void Try(string s = "", int i = 0){
	if(i == n){
		int tmp1 = 0;
		int tmp2 = w;
		for(int i = 0; i < n; ++i){
			if(s[i] == '1'){
				tmp1 += c[i];
				tmp2 -= a[i];
			}
		}
		if(tmp2 >= 0){
			if(tmp1 >= fopt){
				fopt = tmp1;
				xopt = s;
			}
		}
		return;
	}
	Try(s + "0", i + 1);
	Try(s + "1", i + 1);
}

const ll mod = 1e9 + 7;
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> w;
	a.resize(n);
	c.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	Try();
	cout << fopt << '\n';
	for(int i = 0; i < n; ++i){
		cout << xopt[i] << ' ';
	}

    return 0;
}

