
// created: 2023-05-26 17:55:31
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		
		int n1,n2,n3;
		cin >> n1 >> n2 >> n3;	
		
		map<int, int> mp1;
		int tmp;
		for(int i = 0; i < n1; ++i){
			cin >> tmp;
			mp1[tmp]++;
		}
		map<int, int> mp2;
		for(int i = 0; i < n2; ++i){
			cin >> tmp;
			mp2[tmp]++;
		}
		map<int,int> mp3;
		for(int i = 0; i < n3; ++i){
			cin >> tmp;
			mp3[tmp]++;
		}
		map<int, int> mpp1;
		for(auto p : mp2){
			if(mp1.find(p.first) != mp1.end()){
				mpp1[p.first] = min(p.second, mp1.find(p.first)->second);
			}
		}
		map<int, int> mpp2;
		for(auto p : mp3){
			if(mpp1.find(p.first) != mpp1.end()){
				mpp2[p.first] = min(p.second, mpp1.find(p.first)->second);
			}
		}
		if(mpp2.size() == 0){
			cout << "NO";
		}else{
			for(auto p: mpp2){
				for(int i = 0; i < p.second; ++i){
					cout << p.first << ' ';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}

