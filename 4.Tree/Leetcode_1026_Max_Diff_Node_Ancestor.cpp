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

class Solution {
public:

	pair<int, int> dfs(TreeNode* root, int &ans) {
		if (root == nullptr) {
			return {INT_MIN, INT_MAX};
		}

		auto l = dfs(root->left, ans);
		auto r = dfs(root->right, ans);

		if ((l.ff == INT_MIN && l.ss == INT_MAX) && (r.ff == INT_MIN && r.ss == INT_MAX)) {
			return {root->val, root->val};
		}

		int mn = min({l.ss, r.ss});
		int mx = max({l.ff, r.ff});

		int val1 = abs(mn - (root->val));
		int val2 = abs(mx - (root->val));

		ans = max({ans, val1, val2});

		mn = min(mn, root->val);
		mx = max(mx, root->val);

		return {mx, mn};
	}

	int maxAncestorDiff(TreeNode* root) {

		int ans1 = 0;
		auto l = dfs(root->left, ans1);
		int ans2 = 0;
		auto r = dfs(root->right, ans2);

		int ans = 0;

		int mn = min({l.ss, r.ss});
		int mx = max({l.ff, r.ff});

		int val1 = abs(mn - (root->val));
		int val2 = abs(mx - (root->val));

		ans = max({ans, ans1, ans2, val1, val2});

		return ans;
	}
};