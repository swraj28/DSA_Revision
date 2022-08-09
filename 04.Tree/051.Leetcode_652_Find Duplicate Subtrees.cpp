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

	string dfs(TreeNode* root, unordered_map<string, int> &m, vector<TreeNode*> &ans) {
		if (root == nullptr) {
			return "n";
		}

		auto l = dfs(root->left, m, ans);
		auto r = dfs(root->right, m, ans);

		string s = to_string(root->val) + "->" + l + "->" + r;

		m[s]++;

		if (m[s] == 2) {
			ans.pb(root);
		}

		return s;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		if (root->left == nullptr && root->right == nullptr) {
			return {};
		}

		vector<TreeNode*> ans;

		unordered_map<string, int> m;

		dfs(root, m, ans);

		return ans;
	}
};