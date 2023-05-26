
// created: 2023-05-26 23:42:01
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
unordered_set<int> h;
void qry(Node* root, int height = 0){
	if(!root){
		h.insert(height);
		return;
	}
	qry(root->left, height + 1);
	qry(root->right, height + 1);
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		h.clear();
		cin >> n;
		Node* root = nullptr;
		for(int i = 0; i < n; ++i){
			int a,b;
			char c;
			cin >> a >> b >> c;
			if(!root)
				root = new Node(a);
			bld(root, a,b,c);
		}
		qry(root);
		cout << (h.size() == 1 ? 1 : 0) << '\n';
	}

	return 0;
}

