
// created: 2023-05-26 17:49:56
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a(5);
bool flag = false;

void Try(int i = 1, int res = a[0]){
	if(flag) 
		return;
	if(i == 5){
		if(res == 23)
			flag = true;
		return;
	}	
	Try(i + 1, res + a[i]);
	Try(i + 1, res * a[i]);
	Try(i + 1, res - a[i]);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		flag = false;
		for(int i = 0; i < 5; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		do{
			Try();
		}while(!flag && next_permutation(a.begin(), a.end()));
		cout << (flag ? "YES" : "NO") << '\n';
	}
	return 0;
}

