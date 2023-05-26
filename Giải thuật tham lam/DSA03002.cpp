
// created: 2023-05-26 17:52:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int change1(int n){
	string s = to_string(n);
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '6'){
			s[i] = '5';
		}
	}	
	int res = stoi(s);
	return res;
}
int change2(int n){
	string s = to_string(n);
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '5'){
			s[i] = '6';
		}
	}	
	int res = stoi(s);
	return res;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);


		int a, b;
		cin >> a >> b;
		int a1 = change1(a);
		int b1 = change1(b);	
		cout << a1 + b1 << ' ';
		int a2 = change2(a);
		int b2 = change2(b);
		cout << a2 + b2 << '\n';

	return 0;
}

