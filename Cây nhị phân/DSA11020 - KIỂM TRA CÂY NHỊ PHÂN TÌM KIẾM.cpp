
// created: 2023-05-26 23:44:55
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

void buildBST(Node *& root, int val){
	
	if(!root){
		root = new Node(val);
		return;
	}
	
	if(val < root->val)
		buildBST(root->left, val);
	else if(val > root->val)
		buildBST(root->right, val);	
}

void postOrder(Node* root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << ' ';
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();
	while(t--){
		int n;
		cin >> n;	
		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];	
		bool flag = true;
		for(int i = 0; i < n - 1; ++i){
			if(a[i] >= a[i + 1]) flag = false;
		}	
		cout << (flag ? 1 : 0) << '\n';
	}

	return 0;
}


