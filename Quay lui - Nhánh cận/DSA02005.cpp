
// created: 2023-05-26 17:38:44
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
int a[100][100];
bool flag = false;

void backtrack(string s = "", int x = 0, int y = 0){
	

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
		string s;
		cin >> s;
		do{
			cout << s << ' ';
		}while(next_permutation(s.begin(), s.end()));
		cout << '\n';
	}
	return 0;
}


