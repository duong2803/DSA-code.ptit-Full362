
// created: 2023-05-26 23:41:10
// author: Nguyen Tung Duong

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node{
public:
	Node* left = nullptr;
	Node* right = nullptr;
	string val;

	Node();
	Node(string val){
		this->val = val;
	}
};

bool isOperator(string s){
	return s == "+" || s == "-" || s == "*" || s == "/";
}

int n;

int cal(Node* root){
	if(!root) return 0;
	if(!isOperator(root->val))
		return stoi(root->val);	

	int op1 = cal(root->left);
	int op2 = cal(root->right);
	int ans;
	if(root->val == "+")
		ans = op1 + op2;
	else if(root->val == "-")
		ans = op1 - op2;
	else if(root->val == "*")
		ans = op1 * op2;
	else if(root->val == "/")
		ans = op1 / op2;
	return ans;
}

Node* buildTree(vector<string> &tmp, int i = 0){
	
	if(i >= n)
		return nullptr;
	Node* root = new Node(tmp[i]);
	root->left = buildTree(tmp, i * 2 + 1);
	root->right = buildTree(tmp, i * 2 + 2);
	return root;
}
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		cin >> n;
		vector<string> tmp(n);
		for(int i = 0; i < n; ++i){
			cin >> tmp[i];	
		}	
		Node* root = buildTree(tmp);
		cout << cal(root) << '\n';
	}

	return 0;
}


