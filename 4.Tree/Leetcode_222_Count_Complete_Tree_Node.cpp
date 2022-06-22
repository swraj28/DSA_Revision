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
    The Naive Solution to this problem is to count all the nodes by visiting all the nodes in the complete Binary Tree. O(Node).

    For a perfect Binary Tree the total number of nodes is (1<<l)-1. where l is the level of the tree.

    A complete can be considerd as a tree that contains various subtrees that are perfect in nature.
*/

// T.c:- (log(node))^2

/*
   Reason :-


*/

class Solution {
public:
	int countNodes(TreeNode* root) {

		if (root == nullptr) {
			return 0;
		}

		TreeNode* left_root = root, *right_root = root;

		int left_level = 0, right_level = 0;

		while (left_root != nullptr) {
			left_level++;
			left_root = left_root->left;
		}

		while (right_root != nullptr) {
			right_level++;
			right_root = right_root->right;
		}

		if (left_level == right_level) {
			return (1 << left_level) - 1;
		}

		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};