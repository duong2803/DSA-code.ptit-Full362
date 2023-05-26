
// created: 2023-05-26 17:39:46
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
unordered_set<int> col;
unordered_set<int> negDia;
unordered_set<int> posDia;
int cnt;
void backtrack(int x = 0){

	if(x == n){
		++cnt;
		return;
	}
	for(int y = 0; y < n; ++y){
		if(col.find(y) == col.end() && negDia.find(x - y) == negDia.end() && posDia.find(x + y) == posDia.end()){ 
			col.insert(y);
			negDia.insert(x - y);
			posDia.insert(x + y);
			backtrack(x + 1);
			negDia.erase(x - y);
			posDia.erase(x + y);
			col.erase(y);
		}
	}
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
		col.clear();
		negDia.clear();
		posDia.clear();
		cnt = 0;
		cin >> n;
		backtrack();	
		cout << cnt << '\n';	
	}	

	return 0;
}


