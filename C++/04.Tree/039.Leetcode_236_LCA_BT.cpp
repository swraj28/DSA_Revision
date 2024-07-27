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

/*
  The lowest common ancestor is defined between two nodes p and q as the
  lowest node in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself).
*/

/*
Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the binary tree. In the worst case we might be visiting all the nodes of the binary tree.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed binary tree could be N.
*/

class Solution {
public:

	TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode*q) {
		if (root == nullptr) {
			return nullptr;
		}

		if (root == p || root == q) {
			return root;
		}

		auto l = lca(root->left, p, q);
		auto r = lca(root->right, p, q);

		if (l == nullptr && r == nullptr) {
			return nullptr;
		}

		if (l != nullptr && r != nullptr) {
			return root;
		}

		if (l != nullptr) {
			return l;
		}

		return r;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		return lca(root, p, q);
	}
};

// Iterative Solution:-