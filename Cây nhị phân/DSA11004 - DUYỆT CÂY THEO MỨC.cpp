
// created: 2023-05-26 23:41:37
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

void levelOrder(Node* root){

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		while(!q.empty()){
			Node* r = q.front(); q.pop();
			cout << r->val << ' ';
			if(r->left)
				q.push(r->left);
			if(r->right)
				q.push(r->right);				
		
		}
	}

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
			if(!root)
				root = new Node(a);
			bld(root, a,b,c);
		}
		levelOrder(root);
		cout << '\n';
	}

	return 0;
}

