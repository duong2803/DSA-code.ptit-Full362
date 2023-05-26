
// created: 2023-05-26 18:20:19
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int longestPalindrome(string s) {
    int left, right;
    int count;
	int max = 0;
	int left_ans, right_ans;
	
	for(int i = 0; i < s.length(); i++){
	   left = i;
	   right = i;
	while(left >= 0 && right < s.length() && s[left] == s[right]){
		count = right - left + 1;
		right++;
		left--;
}
		if(count > max){
			max = count;
			left_ans = left + 1;
			right_ans = right - 1;
		}
		}
	for(int i = 0; i < s.length() - 1; i++){
		left = i;
		right = i + 1;
		
		while(left >= 0 && right < s.length() && s[left] == s[right]){
			count = right - left + 1;
			right++;
			left--;
			}
		if(count > max){
			max = count;
			left_ans = left + 1;
			right_ans = right - 1;
			}
		}
	string ans = "";
	for(int i = left_ans; i <= right_ans; i++){
		ans += s[i];
		}
	
	return ans.length();
	
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		cout << longestPalindrome(s) << '\n';
	}

	return 0;
}

