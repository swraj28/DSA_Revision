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

	vector<int> res;

	// 1. Recursion:-

	// T.c:- O(nodes) and S.c:- Space Occupied while building recursion Stack--> In worst case O(node)--> skew Tree(Left Skew)
	void inOrder_rec(TreeNode*root) {
		if (root == NULL) {
			return;
		}

		inOrder_rec(root->left);
		res.pb(root->val);
		inOrder_rec(root->right);
	}

	// 2. Iterative Using an Explicit Stack:-

	/*
	   T.c:- O(nodes)
	   S.c:- O(nodes)--> If we consider a left skew tree
	*/

	void in_order_itr(TreeNode*root) {

		stack<TreeNode*>s;
		TreeNode*node = root;

		while (true) {

			if (node != nullptr) {
				s.push(node);
				node = node->left;
			} else {
				if (s.empty() == true) {
					break;
				}

				node = s.top();
				s.pop();

				cout << node->val << " ";

				node = node->right;
			}
		}
	}

	// 3. Morris Traversal For Inorder Traversal:-

	/*
	    T.c:- O(nodes)
	    S.c:- O(1)

	    // Watch striver Video for best Explanation

	*/

	void inOrder_morris(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		TreeNode* curr = root;

		while (curr != nullptr) {

			if (curr->left == nullptr) {
				res.pb(curr->val);
				curr = curr->right;
			} else {

				TreeNode* succ = curr->left;

				while ((succ->right != nullptr) and (succ->right != curr)) {
					succ = succ->right;
				}

				if (succ->right == nullptr) {
					succ->right = curr;
					curr = curr->left;
				} else { //This condition arises when the left subtree is entirely processed. (Remove the connection otherwise infinite loop will occur)
					succ->right = nullptr;
					res.pb(curr->val);   // print the root node
					curr = curr->right;
				}
			}
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {

		// in_order_itr(root);

		inOrder_morris(root);

		return res;
	}
};