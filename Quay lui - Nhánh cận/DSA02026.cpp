
// created: 2023-05-26 17:45:08
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

string op = "+-*/";
vector<string> res;

void check(){

	int n1 = stoi(s.substr(0,2));
	int n2 = stoi(s.substr(5,2));
	int n3 = stoi(s.substr(10,2));
	if(s[3] == '+'){
		if(n1 + n2 == n3){
			res.push_back(s);
		}
	}else if(s[3] == '-'){
		if(n1 - n2 == n3){
			res.push_back(s);
		}
	}else if(s[3] == '*'){
		if(n1 * n2 == n3){
			res.push_back(s);
		}
	}else if(s[3] == '/'){
		if(n1 / n2 == n3){
			res.push_back(s);
		}
	}

}

void Try(int i = 0){
	if(i == s.length()){
		check();
		return;
	}
	if(s[i] == '?'){
		if(i == 3){
			for(int j = 0; j < 4; ++j){
				s[i] = op[j];
				Try(i + 1);
				s[i] = '?';
			}
		}else{
			if(i != 0 && i != 5 && i != 10){
				s[i] = '0';
				Try(i + 1);
				s[i] = '?';
			}
			for(char j = '1'; j <= '9'; ++j){
				s[i] = j;
				Try(i + 1);
				s[i] = '?';
			}
		}	
	}else
		Try(i + 1);
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int t;
	cin >> t;

	cin.ignore();

	while(t--){
		res.resize(0);
		getline(cin, s);
		Try();
		if(res.size() == 0){
			cout << "WRONG PROBLEM!\n";
		}else
			cout << *min_element(res.begin(), res.end()) << '\n';	
	}

	return 0;
}
