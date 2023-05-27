
// created: 2023-05-26 18:36:19
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
	
	vector<int> st;
	string s;
	while(getline(cin, s)){
		stringstream ss(s);
		string tmp;
		vector<string> a;
		while(ss >> tmp){
			a.push_back(tmp);
		}
		if(a.size() == 1){
			if(a[0] == "show"){
				if(st.size() > 0){
					for(int i : st){
						cout << i << ' ';
					}
				}else{
					cout << "empty";
				}
				cout << '\n';
			}else if(a[0] == "pop"){
				st.pop_back();
			}
		}else{
			int k = stoi(a[1]);
			if(a[0] == "push"){
				st.push_back(k);
			}
		}
	}	
	
	return 0;
}


