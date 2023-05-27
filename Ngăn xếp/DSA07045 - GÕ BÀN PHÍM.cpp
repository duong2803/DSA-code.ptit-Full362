
// created: 2023-05-26 18:43:26
// author: Nguyen Tung Duong

#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
	
int main(int argc, char *argv[])
{

		string s;
		cin >> s;
		string res = "";
		stack<char> st;
		for(char c : s){
			if(c == '<'){
				if(res.length() != 0){
					st.push(res.back());
					res.pop_back();
				}
			
			}else if(c == '>'){
				if(st.size() != 0){
					res += st.top();
					st.pop();
				}
			}else if(c == '-'){
				if(res.length() != 0){
					res.pop_back();
				}
			}else
				res += c;
				
			
		}
		while(!st.empty()){
			res += st.top();
			st.pop();
		}
		cout << res;
	
}
