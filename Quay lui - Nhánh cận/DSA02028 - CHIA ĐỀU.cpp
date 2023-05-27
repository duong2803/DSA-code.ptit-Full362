
// created: 2023-05-26 17:49:27
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, K;
vector<int> a;
int cnt = 0;

void Try(int i = 0, int k = K, vector<int> tmp = {}){
	
	if(i == n){
		if(k == 0){

			bool flag = true;
			for(int j = 0; j < K - 1; ++j){
				if(tmp[j] != tmp[j + 1])
					flag = false;
			}
			if(flag) ++cnt;
		}
		return;
	}

	if(tmp.size() == 0){
		tmp.push_back(a[i]);
		Try(i + 1, k - 1, tmp);
	}else{
		if(k > 0){
			tmp.push_back(a[i]);
			Try(i + 1, k - 1, tmp);
			tmp.pop_back();
		}
		tmp[tmp.size() - 1] += a[i];
		Try(i + 1, k, tmp);
		tmp[tmp.size() - 1] -= a[i];
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while(t--){
		cnt = 0;
		cin >> n >> K;
		a.clear();
		a.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		Try();
		cout << cnt << '\n';
	}	

	return 0;
}

