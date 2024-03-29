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

// The brute force approach is to store the value of the tree in a vector and sorting it, making it the inorder traversal of tree. Now while doing the inordr
// traversal match the values stored in the vector and on the tree node, if not matched then place the correct value on the tree node .

// 1. Using Inorder Traversal (DFS):-

/*
    The key idea here is that the inorder traversal of a BST is a sorted Array. We will use the Two Pointers Techniques to
    solve two swapped numbers (using prev and curr pointers).

*/

class Solution {
public:

	TreeNode* p1 = nullptr, *c1 = nullptr, *p2 = nullptr, *c2 = nullptr; // To understand about the pointers see the note on leetcode.

	TreeNode* prev = nullptr;

	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		dfs(root->left);

		if (prev == nullptr) {
			prev = root;
		} else {
			if ((prev->val) > (root->val)) {
				if (p1 == nullptr) {
					p1 = prev;
					c1 = root;
				} else {
					p2 = prev;
					c2 = root;
				}
			}
			prev = root;
		}

		dfs(root->right);
	}

	void recoverTree(TreeNode* root) {

		dfs(root);

		if (p2 == nullptr) {
			swap(p1->val, c1->val);
		} else {
			swap(p1->val, c2->val);
		}
	}
};

// 2. Using Morris Traversal of Inorder:-

class Solution {
public:

	TreeNode* p1 = nullptr, *c1 = nullptr, *p2 = nullptr, *c2 = nullptr;

	TreeNode* prev = nullptr;

	void recoverTree(TreeNode* root) {

		if (root == nullptr) {
			return;
		}

		TreeNode* curr = root;

		while (curr != nullptr) {

			if (curr->left == nullptr) {
				if (prev == nullptr) {
					prev = curr;
				} else {
					if ((prev->val) > (curr->val)) {
						if (p1 == nullptr) {
							p1 = prev;
							c1 = curr;
						} else {
							p2 = prev;
							c2 = curr;
						}
					}
					prev = curr;
				}

				curr = curr->right;
			} else {

				TreeNode* succ = curr->left;

				while ((succ->right != nullptr) && (succ->right != curr)) {
					succ = succ->right;
				}

				if (succ->right == curr) {

					succ->right = nullptr;

					if (prev == nullptr) {
						prev = curr;
					} else {
						if ((prev->val) > (curr->val)) {
							if (p1 == nullptr) {
								p1 = prev;
								c1 = curr;
							} else {
								p2 = prev;
								c2 = curr;
							}
						}
						prev = curr;
					}

					curr = curr->right;
				} else {
					succ->right = curr;
					curr = curr->left;
				}
			}
		}

		if (p2 == nullptr) {
			swap(p1->val, c1->val);
		} else {
			swap(p1->val, c2->val);
		}
	}
};

