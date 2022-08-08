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

// This question can be divided into two parts.

//  (Finding the lowest common Ancestor for startValue and destValue) + (finding the path lca to startValue and destValue).

class Solution {
public:

	TreeNode* lca(TreeNode* root, int & p, int &q) {
		if (root == nullptr) {
			return nullptr;
		}

		if (root->val == p || root->val == q) {
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

	bool recur(TreeNode* root, int &target, string &ans) {
		if (root == nullptr) {
			return false;
		}

		if (root->val == target) {
			return true;
		}

		ans += 'L';

		bool rec_res = recur(root->left, target, ans);
		if (rec_res) {
			return true;
		}

		ans.pop_back();

		ans += 'R';

		rec_res = recur(root->right, target, ans);
		if (rec_res) {
			return true;
		}

		ans.pop_back();

		return false;
	}

	string getDirections(TreeNode* root, int startValue, int destValue) {

		TreeNode* pivot = lca(root, startValue, destValue);

		string a = "", b = "";

		recur(pivot, startValue, a);
		recur(pivot, destValue, b);

		for (auto &ele : a) {
			ele = 'U';
		}

		return (a + b);
	}
};