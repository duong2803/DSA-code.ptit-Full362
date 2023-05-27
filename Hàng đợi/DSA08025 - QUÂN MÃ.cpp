
// created: 2023-05-26 23:21:13
// author: Nguyen Tung Duong

#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int dx[8] = {-2,-2,-1,1,2,2,-1,1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	
	while(t--){
		string s1, s2;
		cin >> s1 >> s2;
		queue<pair<string, int>> q;
		
		q.push({s1, 0});
		
		while(!q.empty()){
	    	pair<string,int> fr = q.front(); q.pop();
	    	if(fr.first == s2){
	    		cout << fr.second <<  '\n';
	    		break;
	    	}
	    	for(int i = 0; i < 8; ++i){
	        	char c1 = fr.first[0] + dx[i];
	        	char c2 = fr.first[1] + dy[i];
	        	if(c1 <= 'h' && c1 >= 'a' && c2 >= '1' && c2 <= '8'){
	        	  	 string v(2,'0');
	        	  	 v[0] = c1; v[1] = c2;
	        	  	 q.push({v, fr.second + 1});
	        	  }
	    	}
		}
	}
	
}
