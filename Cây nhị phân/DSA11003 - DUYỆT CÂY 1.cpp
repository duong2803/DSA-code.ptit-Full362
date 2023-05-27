
// created: 2023-05-26 23:41:25
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
vector<int> in;
vector<int> pre;

int cnt = 0;
Node* bld(int l1 = 0, int r1 = n - 1, int l2 = 0){
	if(l1 > r1)
		return nullptr;
	Node* root = new Node(pre[l2]);
	auto it = find(	in.begin(), in.end(), pre[l2]);
	int m = it - in.begin();
	root->left = bld(l1, m - 1, l2 + 1);
	root->right = bld(m + 1, r1, l2 + m - l1 + 1);
	return root;
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

	while(t--){
		in.resize(0);
		pre.resize(0);
		cin >> n;
		in.resize(n);
		pre.resize(n);
		
		for(int i = 0; i < n; ++i)
			cin >> in[i];
		for(int i = 0; i < n; ++i){
			cin >> pre[i];
		}
		Node* root = bld();
		postOrder(root);
		cout << '\n';
	}

	return 0;
}

