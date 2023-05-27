
// created: 2023-05-26 17:44:08
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool sieve[405];
vector<int> prime;

int s, p, n;
vector<string> res;

void Try(int j = 0, int sum = s, vector<int> tmp = {}){
	if(j == n){
		if(sum == 0){
			string str = "";
			for(int x : tmp){
				str += to_string(x) + " ";
			}	
			res.push_back(str);
		}
		return;
	}
	for(int i = 0; i < prime.size(); ++i){
		if(prime[i] > p && prime[i] <= sum){
			if(tmp.size() == 0){
				tmp.push_back(prime[i]);
				Try(j + 1, sum - prime[i], tmp);
				tmp.pop_back();
			}else if(prime[i] > tmp.back()){
				tmp.push_back(prime[i]);
				Try(j + 1, sum - prime[i], tmp);
				tmp.pop_back();

			}
		}
	}
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	memset(sieve, false, sizeof(sieve));

	for(int i = 2; i * i <= 400; ++i){
		if(!sieve[i]){
			for(int j = i * i; j <= 400; j += i){
				sieve[j] = true;
			}
		}	
	}

	for(int i = 2; i <= 400; ++i){
		if(!sieve[i])
			prime.push_back(i);
	}

	int t;
	cin >> t;

	while(t--){
		res.resize(0);
		cin >> n >> p >> s;
		Try();
		sort(res.begin(), res.end());
		cout << res.size() << '\n';
		for(int i = 0; i < res.size() ; ++i){
			cout << res[i] << '\n';
		}
	}
 	 
    return 0;
}

