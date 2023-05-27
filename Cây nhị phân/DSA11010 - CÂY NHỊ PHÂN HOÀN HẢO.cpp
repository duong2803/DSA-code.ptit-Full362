
// created: 2023-05-26 23:42:28
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

int treeHeight(Node* root){
	if(!root) return 0;
	return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> n;
		Node* root = nullptr;
		for(int i = 0; i < n; ++i){
			int a,b;
			char c;
			cin >> a >> b >> c;
		}
		n += 2;
		cout << ( !(n & n - 1) ? "Yes" : "No") << '\n';
	}

	return 0;
}
