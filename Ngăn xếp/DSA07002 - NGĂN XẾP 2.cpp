
// created: 2023-05-26 18:36:31
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
	
	vector<int> st;
	string s;
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		vector<string> a;
		while(ss >> tmp){
			a.push_back(tmp);
		}
		if(a.size() == 1){
			if(a[0] == "PRINT"){
				if(st.size() > 0){
					cout << st.back();	
				}else{
					cout << "NONE";
				}
				cout << '\n';
			}else if(a[0] == "POP"){
				if(st.size() > 0)
					st.pop_back();
			}
		}else{
			int k = stoi(a[1]);
			if(a[0] == "PUSH"){
				st.push_back(k);
			}
		}
	}	
	
	return 0;
}


