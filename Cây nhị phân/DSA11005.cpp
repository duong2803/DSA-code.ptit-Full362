
// created: 2023-05-26 23:41:50
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
vector<int> in(n);
vector<int> lv(n);

Node* bld(vector<int> levelOrder = lv, int l = 0, int r = n - 1){
	if(levelOrder.size() == 0){
		return nullptr;
	}
	auto it = find(in.begin(), in.end(), levelOrder[0]);
	int m = it - in.begin();
	unordered_set<int> s;
	for(int i = l; i < m; ++i){
		s.insert(in[i]);
	}
	vector<int> v1;
	vector<int> v2;
	for(int i = 1; i < levelOrder.size(); ++i){
		if(s.find(levelOrder[i]) != s.end()){
			v1.push_back(levelOrder[i]);
		}else{
			v2.push_back(levelOrder[i]);
		}
	}
	Node* root = new Node(levelOrder[0]);

	root->left = bld(v1, l, m - 1);
	root->right = bld(v2, m + 1, r);
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
		lv.resize(0);
		cin >> n;
		in.resize(n);
		lv.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> in[i];
		for(int i = 0; i < n; ++i)
			cin >> lv[i];

		Node* root = bld();
		postOrder(root);
		cout << '\n';
	}
	return 0;
}

