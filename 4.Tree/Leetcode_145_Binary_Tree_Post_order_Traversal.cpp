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

// L R N
void postOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

void post_order_itr(TreeNode*root) { //using 2 stacks
	if (root == NULL)return;

	stack<TreeNode*>s1, s2;
	s1.push(root);
	TreeNode*curr;

	while (!s1.empty()) {
		curr = s1.top();
		s1.pop();
		s2.push(curr);

		if (curr->left)s1.push(curr->left);
		if (curr->right)s1.push(curr->right);
	}

	while (!s2.empty()) {
		curr = s2.top();
		cout << curr->val << " ";
		s2.pop();
	}
}

// Revise it many times to make proper understanding:-

// T.c:- O(2*n)--> n for visiting every node and n while reverting back

void post_order_itr_1(TreeNode*root) { //using 1 stack

	stack<TreeNode*> s;

	TreeNode*curr = root;

	while (!s.empty() or curr != NULL) {

		while (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}

		TreeNode*temp = s.top()->right;

		if (temp == NULL) {
			temp = s.top();
			cout << temp->val << " ";
			s.pop();

			while (!s.empty() and temp == s.top()->right) { // overall it will take O(n) time
				temp = s.top();
				cout << temp->val << " ";
				s.pop();
			}
		} else {
			curr = temp;
		}
	}
}