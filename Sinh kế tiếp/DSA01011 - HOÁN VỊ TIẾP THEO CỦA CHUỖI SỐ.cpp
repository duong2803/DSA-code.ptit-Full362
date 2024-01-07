
// created: 2023-05-26 17:34:40
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n, k;
int a[100];
int b[100];

bool Sinh(){
	int i = k;
	while(a[i] == n - k + i && i >= 1)
		--i;
	if(i == 0){
		return false;
	}
	a[i]++;
	for(int j = i + 1; j <= k; ++j){
		a[j] = a[j - 1] + 1;
	}
	return true;	
}

void solve(){
	for(int i = 1; i <= k; ++i){
		a[i] = b[i];
	}
	if(!Sinh()){
		cout << k;
	}else{
		int cnt = 0;
		for(int i = 1; i <= k; ++i){
			bool flag = true;
			for(int j = 1; j <= k; ++j){
				if(a[i] == b[j]) 
					flag = false;
			}
			if(flag) ++cnt;
		}	
		cout << cnt;
	}
}
int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string a;
		cin >> k >> a;
		cout << k << ' ';		
		if(!next_permutation(a.begin(), a.end())){
			cout << "BIGGEST";
		}else{
			cout << a;	
		}
		cout << '\n';
	}
	return 0;
}


