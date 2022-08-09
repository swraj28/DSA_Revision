#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

//Definition for a binary tree Node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Each node has either 2 or 0 children .

bool is_full_binary_tree(TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	if (root->left == NULL and root->right == NULL) {
		return true;
	}

	if (root->left == NULL or root->right == NULL) {
		return false;
	}

	if (root->left and root->right) {
		return is_full_binary_tree(root->left) and is_full_binary_tree(root->right);
	}
}

//Iterative:-

bool is_full_binary_tree_itr(TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();

		if (temp->left == NULL and temp->right == NULL) {
			continue;
		}

		if (temp->left == NULL or temp->right == NULL) {
			return false;
		}
		q.push(temp->left);
		q.push(temp->right);
	}

	return true;
}