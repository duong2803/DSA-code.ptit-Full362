
// created: 2023-05-26 17:44:33
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[8][8];
int res = 0;

unordered_set<int> s1, s2, s3;

void Try(int row = 0, int s = 0){
	if(row == 8){
		res = max(res, s);
		return;
	}

	for(int i = 0; i < 8; ++i){
		if(s1.find(i) == s1.end() && s2.find(i + row) == s2.end() && s3.find(i - row) == s3.end()){
			s1.insert(i);
			s2.insert(i + row);
			s3.insert(i - row);
			Try(row + 1, s + a[i][row]);
			s1.erase(i);
			s2.erase(i + row);
			s3.erase(i - row);
		}
	}
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	


	int t;
	cin >> t;

	while(t--){
		res = 0;
		s1.clear();
		s2.clear();
		s3.clear();
		for(int i = 0; i < 8; ++i){
			for(int j = 0; j < 8; ++j)
				cin >> a[i][j];
		}
		Try();
		cout << res << '\n';	
	}
 	 
    return 0;
}

