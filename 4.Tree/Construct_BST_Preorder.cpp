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

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

/*
   The brute force can be for every node iterate over the entire tree to find its correct position like where it can be placed.

   T.c:- O(n^2)
*/


// Optimized Approach 1:-  (Using Upper Bound and Lower Bound)

int pre_idx = 0;

TreeNode* build_tree(vector<int> &preorder, int l, int r) {

    if (pre_idx >= preorder.size()) {
        return nullptr;
    }

    if ((preorder[pre_idx] >= l) and (preorder[pre_idx] <= r)) {

    } else {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[pre_idx++]);

    root->left = build_tree(preorder, l, (root->val));
    root->right = build_tree(preorder, (root->val), r);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder) {

    return build_tree(preorder, INT_MIN, INT_MAX);
}

//***************************************************************************************************************

// Approach 2:- Using Upper Bound only.

int pre_idx = 0;

TreeNode* build_tree(vector<int> &preorder, int bound) {

    if (pre_idx >= preorder.size()) {
        return nullptr;
    }

    if (preorder[pre_idx] > bound) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[pre_idx++]);

    root->left = build_tree(preorder, (root->val));
    root->right = build_tree(preorder, bound);

    return root;
}

//******************************************************************************

TreeNode *bstFromPreorder(vector<int> &preorder) {

    return build_tree(preorder, INT_MAX);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}