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

	bool is_complete_binary_tree_itr(TreeNode* root) {

		// Base Case: An empty tree
		// is complete Binary Tree
		if (root == NULL) {
			return true;
		}

		// Create an empty queue
		queue<TreeNode*> q;
		q.push(root);

		// Create a flag variable which will be set true
		// when a non full Node is seen

		bool flag = false;

		while (!q.empty()) {

			TreeNode*temp = q.front();
			q.pop();

			if (temp->left) {
				if (flag == true) {
					return false;
				}
				q.push(temp->left);
			} else {
				flag = true;
			}

			if (temp->right) {
				if (flag == true) {
					return false;
				}
				q.push(temp->right);
			} else {
				flag = true;
			}
		}

		return true;
	}

	bool isCompleteTree(TreeNode* root) {

		return is_complete_binary_tree_itr(root);
	}
};