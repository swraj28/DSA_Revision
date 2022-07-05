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

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

//Recursive Implementation:-
node* buildBST(node* root, int data) {
	if (root == NULL) {
		node* n = new node(data);
		root = n;
		return root;
	}

	if (data > root->data) {
		root->right = buildBST(root->right, data);
	} else {
		root->left = buildBST(root->left, data);
	}

	return root;
}

// 4 2 6 1 3 5 7 -1

node* insert() {
	node* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {

		root = buildBST(root, data);

		cin >> data;
	}

	return root;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	node* root = insert();

	return 0;
}