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

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

/*
    Similar to Vertical Order Traversal and Vertical Width of The Binary Tree.
*/

class Solution {
public:

	vector<int> v;

	void verticalTraversal(Node* root) {

		if (root == nullptr) {
			return ;
		}

		queue<pair<Node*, int>> q;
		q.push({root, 0});

		map<int, int> m;

		while (true) {

			int sze = q.size();
			if (sze == 0) {
				break;
			}

			while (sze--) {

				auto p = q.front();
				q.pop();

				int val = p.first->data;
				int angle = p.second;

				if (m.count(angle) == 0) {
					m[angle] = val;
				}

				if (p.first->left) {
					q.push({p.first->left, (angle - 1)});
				}

				if (p.first->right) {
					q.push({p.first->right, (angle + 1)});
				}
			}
		}

		for (auto &it : m) {
			v.pb(it.ss);
		}
	}

	vector<int> topView(Node *root) {

		verticalTraversal(root);

		return v;
	}
};