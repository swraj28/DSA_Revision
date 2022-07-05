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

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) { //constructor
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

node* buildTree(node* root) {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new node(data);
	}

	root->left = buildTree(root->left);
	root->right = buildTree(root->right);

	return root;
}

//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

node* buildTree_1(node* root) {

	int data;
	string val;

	cin >> data >> val;

	if (root == NULL) {
		root = new node(data);
	}

	if (val == "true") {
		root->left = buildTree_1(root->left);
	}

	cin >> val;

	if (val == "true") {
		root->right = buildTree_1(root->right);
	}
	return root;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	node* root = NULL;
	root = buildTree(root);

	node* root_1 = nullptr;

	root_1 = buildTree_1(root_1);

	return 0;
}