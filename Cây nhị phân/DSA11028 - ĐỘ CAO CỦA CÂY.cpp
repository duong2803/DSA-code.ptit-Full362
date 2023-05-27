
// created: 2023-05-26 23:47:45
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

vector<int> adj[100001];
int n;
int dfs(int u = 1){
	
	if(adj[u].size() == 0) return 0;
	int height = 0;
	for(int v: adj[u]){
		height = max(height, dfs(v));
	}
	return height + 1;

}
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();
	while(t--){
		memset(adj, {}, sizeof(adj));	
		cin >> n;
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		cout << dfs() << '\n';
	}

	return 0;
}


