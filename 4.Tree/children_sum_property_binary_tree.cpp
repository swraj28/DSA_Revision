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

/*
   Problem Statement:- You are given a binary tree .you have to update the node value of the binary tree in such a way such that root value gets equal to the sum
                       values of the left child and right child.

                       The only operation that we are allowed to do is during the process is to incerment the node values. Decrementing is not allowed.

    // Watch striver video for better explanation :- https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30&t=702s&ab_channel=takeUforward
*/

class Solution {
public:

	void reorder(TreeNode * root) {

		if (root == NULL) return;

		int child = 0;

		if (root -> left) {
			child += root -> left -> val;
		}

		if (root -> right) {
			child += root -> right -> val;
		}

		if (child < (root -> val)) {
			if (root -> left) root -> left -> val = root -> val;
			else if (root -> right) root -> right -> val = root -> val;
		}

		reorder(root -> left);
		reorder(root -> right);

		int tot = 0;

		if (root -> left) tot += root -> left -> val;
		if (root -> right) tot += root -> right -> val;
		if (root -> left || root -> right) root -> val = tot;
	}

	int children_sum_property(TreeNode* root) {

		reorder(root);
	}
};