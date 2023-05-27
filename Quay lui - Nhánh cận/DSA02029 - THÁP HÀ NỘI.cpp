
// created: 2023-05-26 17:41:06
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void dp(int n, char a, char b, char c){
	if(n == 0){
		return;
	}
	dp(n - 1, a, c, b);
	cout << a << " -> " << c << '\n';
	dp(n - 1, b, a, c);
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; 
	cin >> n;
	
	dp(n, 'A', 'B', 'C');
 
	return 0;
}

