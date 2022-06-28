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

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {

		string ans = "";

		if (root == nullptr) {
			return ans;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			ans += to_string(node->val);
			ans += ',';

			if (node->left) {
				q.push(node->left);
			} else {
				ans += "#";
				ans += ',';
			}


			if (node->right) {
				q.push(node->right);
			} else {
				ans += "#";
				ans += ',';
			}
		}

		cout << ans << endl;

		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

		if (data == "") {
			return nullptr;
		}

		int idx = 0;
		string val = "";

		while (data[idx] != ',') {
			val += data[idx];
			idx++;
		}

		TreeNode* root = new TreeNode(stoi(val));

		idx++;

		int n = data.length();

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			int cnt = 0;

			val = "";

			while (cnt < 2) {
				if (data[idx] == ',') {
					if (val == "#") {
					} else {
						if (cnt == 0) {
							node->left = new TreeNode(stoi(val));
							q.push(node->left);
							cnt++;
						} else {
							node->right = new TreeNode(stoi(val));
							q.push(node->right);
							cnt++;
						}
					}

					val = "";
					idx++;
				} else {
					val += data[idx];
					idx++;
				}
			}
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));