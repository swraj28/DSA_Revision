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
	Video Link:- https://www.youtube.com/watch?v=B89In5BctFA&list=TLGGmXFc5cG2IQIyODAxMjAyMg&ab_channel=Pepcoding

    Key Concept:-
    			1. Find all the Nodes in (Target Node to Root) Path and store in a vector.
    			2. Taking the target node level as zero level iterte over the vector that contains Nodes to Root Path and find the node
    				which are (k- level) below that node ((k-level)>=0).

    			3. We Need to Add a Blocker (See Video For More Details).
*/

// class Solution {
// public:

// 	vector<TreeNode*> nodeToRootPath_(TreeNode* root, int data) {

// 		if (root == nullptr) {
// 			return {};
// 		}

// 		if (root->val == data) {

// 			vector<TreeNode*> v;
// 			v.pb(root);

// 			return v;
// 		}

// 		vector<TreeNode*> left = nodeToRootPath_(root->left, data);

// 		if (left.size()) {
// 			left.pb(root);
// 			return left;
// 		}

// 		vector<TreeNode*> right = nodeToRootPath_(root->right, data);

// 		if (right.size()) {
// 			right.pb(root);
// 			return right;
// 		}

// 		return {};
// 	}

// 	vector<int> ans;

// 	void Nodes_Below_Target(TreeNode* root, int k, int blocker) {
// 		if (root == nullptr) {
// 			return;
// 		}

// 		if ((root->val) == blocker) {
// 			return;
// 		}

// 		if (k == 0) {
// 			ans.pb(root->val);
// 			return;
// 		}

// 		Nodes_Below_Target(root->left, k - 1, blocker);
// 		Nodes_Below_Target(root->right, k - 1, blocker);
// 	}

// 	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

// 		if (k == 0) {
// 			ans.pb(target->val);
// 			return ans;
// 		}

// 		vector<TreeNode*> Node_To_Root_Path = nodeToRootPath_(root, target->val);

// 		// for (auto Node : Node_To_Root_Path) {
// 		// 	cout << Node->val << " ";
// 		// }
// 		// cout << endl;

// 		for (int i = 0; i < Node_To_Root_Path.size(); i++) {
// 			if ((i - 1) >= 0) {
// 				Nodes_Below_Target(Node_To_Root_Path[i], k - i, Node_To_Root_Path[i - 1]->val);
// 			} else {
// 				Nodes_Below_Target(Node_To_Root_Path[i], k - i, -1);
// 			}
// 		}

// 		return ans;
// 	}
// };

// Most Intutive Approach :- Try to convert this tree into directed graph without modifying the tree and then simply perform dfs that we do on graph .

// 1.DFS:--

class Solution {
public:

	void child_to_parent_connection(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> & connections) {
		if (root == nullptr) {
			return;
		}

		if (parent != nullptr) {
			connections[root] = parent;
		}

		child_to_parent_connection(root->left, root, connections);
		child_to_parent_connection(root->right, root, connections);
	}

	void dfs(TreeNode* src, int d, unordered_map<TreeNode*, TreeNode*> &connections, unordered_map<TreeNode*, bool> &visited, vector<int> &ans) {
		if (d == 0) {
			ans.pb(src->val);
		}

		visited[src] = 1;

		if (src->left && visited[src->left] == false) {
			dfs(src->left, d - 1, connections, visited, ans);
		}

		if (src->right && visited[src->right] == false) {
			dfs(src->right, d - 1, connections, visited, ans);
		}

		if (connections.count(src)) {
			TreeNode* nbr = connections[src];
			if (visited[nbr] == false) {
				dfs(nbr, d - 1, connections, visited, ans);
			}
		}
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

		if (k == 0) {
			return {target->val};
		}

		unordered_map<TreeNode*, TreeNode*> connections;

		child_to_parent_connection(root, nullptr, connections);

		// after this recursive call we have created an undirected graph

		TreeNode* src = target;

		unordered_map<TreeNode* , bool> visited;

		vector<int> ans;

		dfs(src, k, connections, visited, ans);

		return ans;
	}
};

// 2.BFS:-

class Solution {

	void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {

		queue<TreeNode*> queue;
		queue.push(root);

		while (!queue.empty()) {

			TreeNode* current = queue.front();
			queue.pop();

			if (current->left) {
				parent_track[current->left] = current;
				queue.push(current->left);
			}

			if (current->right) {
				parent_track[current->right] = current;
				queue.push(current->right);
			}
		}
	}

public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

		unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
		markParents(root, parent_track, target);

		unordered_map<TreeNode*, bool> visited;
		queue<TreeNode*> queue;

		queue.push(target);
		visited[target] = true;

		int curr_level = 0;

		while (!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/

			int size = queue.size();

			if (curr_level++ == k) break;

			for (int i = 0; i < size; i++) {

				TreeNode* current = queue.front(); queue.pop();

				if (current->left && !visited[current->left]) {
					queue.push(current->left);
					visited[current->left] = true;
				}

				if (current->right && !visited[current->right]) {
					queue.push(current->right);
					visited[current->right] = true;
				}

				if (parent_track[current] && !visited[parent_track[current]]) {
					queue.push(parent_track[current]);
					visited[parent_track[current]] = true;
				}
			}
		}

		vector<int> result;

		while (!queue.empty()) {
			TreeNode* current = queue.front(); queue.pop();
			result.push_back(current->val);
		}

		return result;
	}
};