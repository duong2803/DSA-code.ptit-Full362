
// created: 2023-05-26 23:43:12
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

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> n;
		Node* root = nullptr;
		map<int, Node*> mp;
		for(int i = 0; i < n; ++i){
			int a, b;
			char c;
			cin >> a >> b >> c;
			if(mp.find(a) == mp.end()){
				root = new Node(a);
				if(c == 'L'){
					root->left = new Node(b);
					mp[b] = root->left;
				}else{
					root->right = new Node(b);
					mp[b] = root->right;
				}
				mp[a] = root;
			}
			else{
				if(c == 'L'){
					mp[a]->left = new Node(b);
					mp[b] = mp[a]->left;
				}else{
					mp[a]->right = new Node(b);
					mp[b] = mp[a]->right;
				}
			}
		}	
		cout << rightLeafSum(root) << '\n';
	}

	return 0;
}

