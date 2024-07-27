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

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

class Solution {
public:

	int dfs(TreeNode* root) {

		if (root == nullptr) {
			return 0;
		}

		auto l = dfs(root->left);
		auto r = dfs(root->right);

		if (l == -1 || r == -1) {
			return -1;
		}

		int temp = abs(l - r);

		if (temp > 1) {
			return -1;
		}

		return max(l, r) + 1;
	}

	bool isBalanced(TreeNode* root) {

		auto x = dfs(root);

		return (x == -1) ? 0 : 1;
	}
};