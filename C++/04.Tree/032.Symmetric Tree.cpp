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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        return is_mirror(root, root);

    }

    bool is_mirror(TreeNode* r1, TreeNode*r2) {

        if (r1 == NULL && r2 == NULL)return true;

        if (r1 == NULL || r2 == NULL)return false;

        if (r1->val == r2->val) {

            bool rec_res = is_mirror(r1->left, r2->right) && is_mirror(r2->right, r1->left); // original tree and mirrored tree

            if (rec_res == true) {
                return true;
            }
        }

        return false;
    }
};