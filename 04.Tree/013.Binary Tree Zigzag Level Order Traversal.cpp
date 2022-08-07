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
	vector<vector<int>> v;

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		if (root == NULL) {
			return v;
		}

		queue<TreeNode*>q;
		q.push(root);

		vector<int> path;
		bool flag = true;

		while (true) {

			int n = q.size();

			if (n == 0) {
				break;
			}

			while (n--) {
				TreeNode*cur = q.front();
				q.pop();
				path.push_back(cur->val);
				if (cur->left) {
					q.push(cur->left);
				}
				if (cur->right) {
					q.push(cur->right);
				}
			}

			if (flag) {
				v.push_back(path);
				path.clear();
				flag = false;
			} else {
				flag = true;
				reverse(path.begin(), path.end());
				v.push_back(path);
				path.clear();
			}
		}

		return v;
	}
};