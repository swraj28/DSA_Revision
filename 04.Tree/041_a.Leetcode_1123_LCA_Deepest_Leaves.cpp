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

// 2 DFS Calls:-

class Solution {
public:

	int depth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		return 1 + max(depth(root->left), depth(root->right));
	}

	TreeNode* lca(TreeNode* root, int d) {
		if (root == nullptr) {
			return nullptr;
		}

		if (d == 1) {
			return root;
		}

		auto l = lca(root->left, d - 1);
		auto r = lca(root->right, d - 1);

		if (l && r) {
			return root;
		}

		if (l) {
			return l;
		}

		return r;
	}

	TreeNode* lcaDeepestLeaves(TreeNode* root) {

		if (root->left == nullptr && root->right == nullptr) {
			return root;
		}

		int d = depth(root);

		return lca(root, d);
	}
};