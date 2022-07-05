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

   Brute Force Solution:- from every node we are going to call the validate BST function, if the given tree is BST then then we can do any traversal to
   find the sum of that bst and return the maximum one. The time complexity is O((node)^2).

*/

// Optimized :- using Post Order Traversal (Building our answer fomr Bottom )

class Solution {
public:
	pair<bool, pair<int, pair<int, int>>> dfs(TreeNode* root, int &ans) {
		if (root == nullptr) {
			return {true, {0, {INT_MAX, INT_MIN}}};
		}

		auto l = dfs(root->left, ans);
		auto r = dfs(root->right, ans);

		if (root->left == nullptr && root->right == nullptr) {
			ans = max(ans, root->val);
			return {true, {root->val, {root->val, root->val}}};
		}

		bool left_bst = l.ff, right_bst = r.ff;

		int left_val = l.ss.ff, right_val = r.ss.ff;

		int left_mn = l.ss.ss.ff, left_mx = l.ss.ss.ss;
		int right_mn = r.ss.ss.ff, right_mx = r.ss.ss.ss;

		if ((left_bst == true) && (right_bst == true)) {

			if ((root->left && root->left->val >= root->val) || (root->right && root->right->val <= root->val) ) {
				return {false, {0, {0, 0}}};
			}

			if (root->val > right_mn || root->val < left_mx) {
				return {false, {0, {0, 0}}};
			}

			int new_val = left_val + right_val + (root->val);

			int new_mn = min({left_mn, right_mn, (root->val)});
			int new_mx = max({left_mx, right_mx, (root->val)});

			ans = max(ans, new_val);

			return {true, {new_val, {new_mn, new_mx}} };
		}

		return {false, {0, {0, 0}}};
	}

	int maxSumBST(TreeNode* root) {

		int ans = 0;
		dfs(root, ans);

		return ans;
	}
};