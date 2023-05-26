
// created: 2023-05-26 17:46:21
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[30];
int n;

bool isPrime(int k){
	if(k <= 1) return false;
	if(k == 2 || k == 3) return true;
	if(k % 2 == 0 || k % 3 == 0) return false;
	for(int i = 5; i * i <= k; i += 6){
		if(k % i == 0 || k % (i + 2) == 0)
			return false;
	}
	return true;
}

void Try(int i = 0, vector<int> tmp = {}){
	if(i == n){
		int sum = 0;
		for(int i = 0; i < tmp.size(); ++i){
			sum += tmp[i];
		}	
		if(isPrime(sum)){
			for(int i = 0; i < tmp.size(); ++i){
				cout << tmp[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	Try(i + 1, tmp);
	tmp.push_back(a[i]);
	Try(i + 1, tmp);
	tmp.pop_back();
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t;
	cin >> t;

	while(t--){
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n, greater<int>());
		Try();
	}
	return 0;
}

