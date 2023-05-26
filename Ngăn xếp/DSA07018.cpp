
// created: 2023-05-26 18:42:12
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();
	while(t--){
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		map<int,int> mp;
		string tmp = "";
		int last;
		for(int i = 0; i < s1.length(); ++i){
			if(s1[i] == '*'){
				last = stoi(tmp);
				tmp = "";
			}
			if(s1[i] == ' ' && tmp.size() > 0){
				mp[stoi(tmp)] += last;
				tmp = "";
			}
			if(s1[i] >= '0' && s1[i] <= '9'){
				tmp += s1[i];
			}	
		}
		mp[stoi(tmp)] += last;
		for(int i = 0; i < s2.length(); ++i){
			if(s2[i] == '*'){
				last = stoi(tmp);
				tmp = "";
			}
			if(s2[i] == ' ' && tmp.size() > 0){
				mp[stoi(tmp)] += last;
				tmp = "";
			}
			if(s2[i] >= '0' && s2[i] <= '9'){
				tmp += s2[i];
			}	
		}
		mp[stoi(tmp)] += last;
		int k = 0;
		for(auto it = mp.rbegin(); it != mp.rend(); ++it){
			k++;
			cout << it->second << "*x^" << it->first;
			if(k < mp.size())
				cout << " + ";
		}

		cout << '\n';
	}

	return 0;
}

