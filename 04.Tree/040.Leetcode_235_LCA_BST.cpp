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

// The Brute Force Approach can be using the technique that we have used to find the lca for a binary tree. But since we are operating on a BST then we can optimze
// our approach .

class Solution {
public:

	TreeNode* lca_BST(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return nullptr;
		}

		if ((root->val >= p->val) && (root->val <= q->val)) {
			return root;
		}

		if ((root->val >= q->val) && (root->val <= p->val)) {
			return root;
		}

		if ((root->val < p->val) && (root->val < q->val)) {
			return lca_BST(root->right, p, q);
		}

		return lca_BST(root->left, p, q);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		return lca_BST(root, p, q);
	}
};

// Iterative Solution:-