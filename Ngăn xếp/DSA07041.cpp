
// created: 2023-05-26 18:41:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
	    int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; ++i){
            if(!st.empty()){
                char c = st.top();
                if(c == '('){
                    if(s[i] == ')'){
                        st.pop();
                    }else{
                        st.push(s[i]);
                    }
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        cout <<  n - st.size() << '\n';		
	}	

	return 0;
}


