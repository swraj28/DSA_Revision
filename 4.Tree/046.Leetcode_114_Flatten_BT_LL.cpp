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

// The most brute force solution (Not allowed store the nodes in a vector).

class Solution {
public:
	vector<TreeNode*> v;
	void flatten(TreeNode* root) {

		if (root == NULL) {
			return;
		}
		pre_order(root);

		for (int i = 1; i < v.size(); i++) {
			v[i - 1]->left = NULL;
			v[i - 1]->right = v[i];
		}
	}

	void pre_order(TreeNode* root) {
		if (root == NULL) {
			return;
		}

		v.push_back(root);
		pre_order(root->left);
		pre_order(root->right);
	}
};

/*

 Appraoch 1:- Use a Prev variable to store the flattend tree and whenever we encounter some new nodes we will attach the previously flattend tree to the
            right of this node.


    Traveral :- (Right) --> (Left) ---> (Root)

    T.c:- O(node)
    S.c:- O(node)--> Recursive Stack Space
*/

class Solution {
public:

	TreeNode* prev = nullptr;

	void dfs(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		dfs(root->right);
		dfs(root->left);

		root->right = prev;
		root->left = nullptr;

		prev = root;
	}

	void flatten(TreeNode* root) {

		dfs(root);

		root = prev;
	}
};

// Appraoch 2:- Using Explicit Stack (Iterative)

class Solution {
public:

	void flatten(TreeNode* root) {

		if (root == nullptr) {
			return;
		}

		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {

			auto top = s.top();
			s.pop();

			if (top->right) {
				s.push(top->right);
			}

			if (top->left) {
				s.push(top->left);
			}

			if (!s.empty()) {
				top->right = s.top();
			}
			top->left = nullptr;
		}
	}
};

// Approach 3:- No extra space

// Thought Process :- Morris Traversal

// Watch Striver Video for proper Explanation

class Solution {
public:

	void flatten(TreeNode* root) {

		if (root == nullptr) {
			return;
		}

		TreeNode* curr = root;

		while (curr != nullptr) {

			if (curr->left != nullptr) {

				TreeNode* prev = curr->left;

				while (prev->right) {
					prev = prev->right;
				}

				prev->right = curr->right;
				curr->right = curr->left;

				curr->left = nullptr;
			}

			curr = curr->right;
		}
	}
};