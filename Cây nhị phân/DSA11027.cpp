
// created: 2023-05-26 23:47:31
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

vector<int> a;
int n;
int cnt;
Node* buildBSTWithArr(int l = 0, int r = n - 1){
	if(l > r)
		return nullptr;
	int m = l + r >> 1;
	Node* root = new Node(a[m]);
	root->left = buildBSTWithArr(l, m - 1);
	root->right =buildBSTWithArr(m + 1, r);
	return root;
}

void leafCount(Node* root){
	if(!root) return;
	if(!root->left && !root->right){
		++cnt;
		return;
	}
	leafCount(root->left);
	leafCount(root->right);
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();
	while(t--){
		cnt = 0;
		cin >> n;	
		a.clear();
		a.resize(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		Node* root = buildBSTWithArr();
		leafCount(root);
		cout << cnt << '\n';
	}

	return 0;
}


