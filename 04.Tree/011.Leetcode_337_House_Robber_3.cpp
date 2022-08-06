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

class Solution {
public:
	unordered_map<TreeNode*, int> dp;

	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		if (dp.count(root)) {
			return dp[root];
		}

		int dontRob = rob(root -> left) + rob(root -> right);

		int robRoot = root -> val;

		if (root -> left) {
			robRoot += rob(root -> left -> left) + rob(root -> left -> right);
		}

		if (root -> right) {
			robRoot += rob(root -> right -> left) + rob(root -> right -> right);
		}

		return dp[root] = max(dontRob, robRoot);
	}

	int rob(TreeNode* root) {

		return dfs(root);
	}
};

// Space Optimized Dynamic programming :-

/*
   Approach:-

The Thief cannot choose the two adjacent nodes right?

Also, If we know the maximum amount the thief can steal for the child and grandchild nodes of the current node,
we can answer the maximum amount for the current node also...Guess Why? [Think for the above condition].

Since, If we choose the current node into our answer, we cannot take the child nodes of the current node right?
Hence, we'd be looking for a maximum answer we can get with grandchild nodes.

When we don't choose current node into our answer, we would look for a maximum answer for left as well as right child nodes.

dp[node v] = max(root->val + dp[left grand child of v] + dp[right grand child of v] , dp[left child of v] + dp[right child of v] ) is the dp relation.

we would maintain a pair<int, int> for every node {max ans child nodes, max ans for grandchild nodes} and recursively calculate the answer for every node.
*/

class Solution {
public:

	pair<int, int> dfs(TreeNode* root) {
		if (root == nullptr) {
			return {0, 0};
		}

		auto l = dfs(root->left);
		auto r = dfs(root->right);

		return {max({root->val + l.ss + r.ss, l.ff + r.ff}), l.ff + r.ff};
	}

	int rob(TreeNode* root) {

		return dfs(root).ff;
	}
};