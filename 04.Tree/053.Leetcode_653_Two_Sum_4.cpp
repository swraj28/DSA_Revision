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

// Approach:- Brute Force (Storing the inorder and then using the technique learned while solving the problem (Two Sum) on Leetcode).

class Solution {
public:
	vector<int> v;
	void Inorder(TreeNode* root) {
		if (root == NULL) {
			return;
		}

		Inorder(root->left);
		v.push_back(root->val);
		Inorder(root->right);
	}

	bool findTarget(TreeNode* root, int k) {

		Inorder(root);
		int n = v.size();
		int s = 0, e = n - 1;
		while (s < e) {
			if (v[s] + v[e] < k) {
				s++;
			} else if (v[s] + v[e] > k) {
				e--;
			} else {
				return true;
			}
		}

		return false;
	}
};

// We cannot enhance the time complexity as in the worst case we need to iterate the element atleast once.

// We can optimize space wise using (BST iterator question we solved)

/**************************************************************************************/

class BSTIterator {

	stack<TreeNode *> myStack;
	bool reverse = true;

public:

	BSTIterator(TreeNode *root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !myStack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *tmpNode = myStack.top();
		myStack.pop();
		if (!reverse) pushAll(tmpNode->right);
		else pushAll(tmpNode->left);

		return tmpNode->val;
	}

private:

	void pushAll(TreeNode *node) {
		for (; node != NULL; ) {
			myStack.push(node);
			if (reverse == true) {
				node = node->right;
			} else {
				node = node->left;
			}
		}
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {

		if (!root) return false;

		BSTIterator l(root, false);
		BSTIterator r(root, true);

		int i = l.next();
		int j = r.next();

		while (i < j) {

			if (i + j == k) return true;

			else if (i + j < k) i = l.next();
			else j = r.next();
		}

		return false;
	}
};