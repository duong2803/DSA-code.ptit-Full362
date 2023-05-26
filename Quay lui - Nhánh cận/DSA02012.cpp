
// created: 2023-05-26 17:39:22
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll f(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; ++i)
        res *= i;
    return res;
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
        ll n, m;
        cin >> n >> m;
        int a[200][200];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }
        cout << f(n + m - 2) / (f(n - 1) * f(m - 1)) << '\n';
    }

    return 0;
}

