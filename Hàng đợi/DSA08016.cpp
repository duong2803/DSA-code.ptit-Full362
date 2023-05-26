
// created: 2023-05-26 23:24:32
// author: Nguyen Tung Duong

#include <bits/stdc++.h>
using namespace std;

string a(10, '0');
int r1[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int r2[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int l1[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int l2[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};
string solved = "1238004765";

unordered_map<string, int> cnt;

void solve()
{
    queue<pair<string, int>> q1;
    pair<string, int> p;
    p.first = a;
    p.second = 0;
    q1.push(p);
    while (!q1.empty())
    {
        pair<string, int> fr = q1.front();
        q1.pop();
        if (cnt.find(fr.first) != cnt.end())
        {
            cout << fr.second + cnt[fr.first] << '\n';
            return;
        }

        if (fr.second == 13)
            break;
        string s1(10, '0');
        string s2(10, '0');
        for (int i = 0; i < 10; ++i)
        {
            s1[i] = fr.first[r1[i]];
        }
        for (int i = 0; i < 10; ++i)
        {
            s2[i] = fr.first[r2[i]];
        }
        q1.push({s1, fr.second + 1});
        q1.push({s2, fr.second + 1});
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pair<string, int> p;
    queue<pair<string, int>> q2;
    p.first = solved;
    p.second = 0;
    q2.push(p);

    while (!q2.empty())
    {
        pair<string, int> fr = q2.front();
        q2.pop();
        cnt.insert(fr);
        if (fr.second == 15)
            break;
        string s1(10, '0');
        string s2(10, '0');
        for (int i = 0; i < 10; ++i)
            s1[i] = fr.first[l1[i]];
        for (int i = 0; i < 10; ++i)
            s2[i] = fr.first[l2[i]];
        q2.push({s1, fr.second + 1});
        q2.push({s2, fr.second + 1});
    }
    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 10; ++i)
            cin >> a[i];
        solve();
    }
    return 0;
}
