
// created: 2023-05-26 23:42:55
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node{
public:
	Node* left = nullptr;
	Node* right = nullptr;
	int val;

	Node();
	Node(int val){
		this->val = val;
	}
};
int n;

void bld(Node *&root, int a, int b, char c){
	if(!root) return;
	if(root->val == a){
		if(c == 'L'){
			root->left = new Node(b);
		}else if(c == 'R'){
			root->right = new Node(b);
		}
	}	
	bld(root->left,a,b,c);
	bld(root->right,a,b,c);
}

bool check(Node* root){
	if(!root->left && !root->right)
		return true;
	if(root->left && !root->right || !root->left && root->right)
		return false;
	return check(root->left) && check(root->right);
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		//Node* root = nullptr;
		//for(int i = 0; i < n; ++i){
			//int a,b;
			//char c;
			//cin >> a >> b >> c;
			//if(!root)
				//root = new Node(a);
			//bld(root, a,b,c);
		//}
		//cout << (check(root) ? 1 : 0) << '\n';
		string s1;
		getline(cin, s1);
		getline(cin, s);
		string s2;
		getline(cin, s2);
		cout << (s1 == s2 ? 1 : 0) << '\n';
	}

	return 0;
}

