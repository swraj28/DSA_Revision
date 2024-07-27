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

//Definition for a binary tree node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Perfect Binary Tree:- All leaf nodes are at same level and every internal nodes have 2 children .

int depth(TreeNode* root) {

	int d = 0;

	while (root != NULL) {
		d++;
		root = root->left;
	}

	return d;
}

bool is_perfect_binary_tree(TreeNode* root, int d, int level = 0) {
	if (root == NULL) {
		return true;
	}

	if (root->left == NULL and root->right == NULL) {
		return (d == level + 1);
	}

	if (root->left == NULL or root->right == NULL) {
		return false;
	}

	return is_perfect_binary_tree(root->left, d, level + 1) && is_perfect_binary_tree(root->right, d, level + 1);
}

bool is_perfect(TreeNode* root) {
	int d = depth(root);

	return is_perfect_binary_tree(root, d);
}

//Iterative appoach:-

bool is_perfect_binary_tree_itr(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	// Push the root TreeNode
	queue<TreeNode*> q;
	q.push(root);

	// Flag to check if leaf nodes have been found
	int flag = 0;

	while (!q.empty()) {

		TreeNode* temp = q.front();
		q.pop();

		// If current TreeNode has both left and right child
		if (temp->left and temp->right) {

			// If a leaf TreeNode has already been found
			// then return false
			if (flag == 1) {
				return false;
			} else {
				q.push(temp->left);
				q.push(temp->right);
			}
			// If a leaf TreeNode is found mark flag as one
		} else if (temp->left == nullptr and temp->right == nullptr) {
			flag = 1;
			// If the current TreeNode has only one child
			// then return false
		} else if (temp->left == nullptr or temp->right == nullptr) {
			return false;
		}
	}
	// If the given tree is perfect return true
	return true;
}