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
	TreeNode* deleteNode(TreeNode* root, int key) {

		if (root == nullptr) {
			return nullptr;
		}

		TreeNode* l = nullptr, *r = nullptr, *p = nullptr, *node = nullptr;

		TreeNode* curr = root;

		while (curr) {
			if (curr->val == key) {
				l = curr->left;
				r = curr->right;
				node = curr;
				break;
			}

			if (curr->val < key) {
				p = curr;
				curr = curr->right;
			} else {
				p = curr;
				curr = curr->left;
			}
		}

		if (node == nullptr) {
			return root;
		}

		if (p == nullptr) {  // Root Node has to be deleted.
			if (r == nullptr) {
				return l;
			}

			if (l == nullptr) {
				return r;
			}

			curr = r;

			while (curr->left) {
				curr = curr->left;
			}

			curr->left = l;

			return r;
		}

		if (r == nullptr && l == nullptr) {

			if (p->left == node) {
				p->left = nullptr;
			} else {
				p->right = nullptr;
			}

			delete node;

			return root;
		}

		if (r) {
			curr = r;

			while (curr->left) {
				curr = curr->left;
			}

			curr->left = l;

			if (p->val > r->val) {
				p->left = r;
			} else {
				p->right = r;
			}

			delete node;

			return root;
		}

		if (p->val > l->val) {
			p->left = l;
		} else {
			p->right = l;
		}

		delete node;

		return root;
	}
};