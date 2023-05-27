
// created: 2023-05-26 23:43:46
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

int rightLeafSum(Node* root){
	if(!root)
		return 0;
	int ans = 0;
	if(root->right && !root->right->left && !root->right->right)
		ans += root->right->val;
	ans += rightLeafSum(root->left);
	ans += rightLeafSum(root->right);
	return ans;
}

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

int sum(Node* root){
	if(!root) return 0;
	return max(sum(root->left), sum(root->right)) + root->val;
}

int res;
void dfs(Node* root){
	if(root){
		if(root->left && root->right)
			res = max(res, root->val + sum(root->left) + sum(root->right));
		dfs(root->left);
		dfs(root->right);
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		res = INT_MIN;
		cin >> n;
		Node* root = nullptr;
		for(int i = 0; i < n; ++i){
			int a, b;
			char c;
			cin >> a >> b >> c;
			if(!root){
				root = new Node(a);
			}
			bld(root, a,b,c);
		}	
		dfs(root);
		cout << res << '\n';
	}

	return 0;
}

