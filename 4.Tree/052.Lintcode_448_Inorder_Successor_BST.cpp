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

// 1. Brute Force:- Store the Inorder traversal in a vector and use upper_Bound function to find the inorder Successor.

// Approach 2:- Iterative Traversal by following the properties of a BST.

class Solution {
public:

	TreeNode* inorder_Successor(TreeNode* root, TreeNode* p, TreeNode* succ = nullptr) {

		while (root) {
			if (root->val < p->val) {
				root = root->right;
			} else {
				if (root->val > p->val) {
					succ = root;
					root = root->left;
				} else {
					root = root->right;
				}
			}
		}

		return succ;
	}

	TreeNode* inorder_Predecessor(TreeNode* root, TreeNode* p, TreeNode* pred = nullptr) {

		while (root) {
			if (root->val > p->val) {
				root = root->left;
			} else {
				if (root->val < p->val) {
					pred = root;
					root = root->right;
				} else {
					root = root->left;
				}
			}
		}

		return pred;
	}

	TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {

		return inorder_Successor(root, p);
	}
};