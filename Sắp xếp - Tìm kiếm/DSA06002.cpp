
// created: 2023-05-26 18:24:43
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

class Num{
public:
	int idx;
	int val;
};


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
		int n, x;
		cin >> n >> x;
		vector<Num> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i].val;
			a[i].idx = i;
		}
		sort(a.begin(), a.end(), [&](Num a1, Num a2){
			if(abs(a1.val - x) == abs(a2.val - x)) return a1.idx < a2.idx;
		   return abs(a1.val - x) < abs(a2.val - x);	
		});
		for(Num i : a){
			cout << i.val << ' ';
		}	
		cout << '\n';
	
	}
    return 0;
}

