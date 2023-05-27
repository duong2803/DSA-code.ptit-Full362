
// created: 2023-05-26 18:35:26
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> a1;
	vector<int> a2;
	for(int i = 0; i < n; i += 2){
		a1.push_back(a[i]);
	}
	for(int i = 1; i < n; i += 2){
		a2.push_back(a[i]);
	}

	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end(), greater<int>());
	int k = 0;
	while(k < a1.size() && k < a2.size()){
		cout << a1[k] << ' ' << a2[k] << ' ';
		++k;
	}

	while(k < a1.size()){
		cout << a1[k] << ' ';
		k++;
	}
	while(k < a2.size()){
		cout << a2[k] << ' ';
		k++;
	}

	return 0;
}

