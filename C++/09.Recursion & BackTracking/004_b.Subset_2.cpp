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

// Time Complexity and Auxiliary Space can be assumed to same as that of subset in case of upperbound Analysis of Time Complexity .

class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums, int n, int si, vector<int> &v) {

        if (si >= n) {
            ans.push_back(v);
            return;
        }

        v.push_back(nums[si]);
        recur(nums, n, si + 1, v);

        v.pop_back();

        while ((si + 1 < n) and (nums[si] == nums[si + 1])) { // Build a Recursive tree on {1,2,2} to understand this while condition.
            si++;
        }

        recur(nums, n, si + 1, v);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> v;

        recur(nums, n, 0, v);

        return ans;
    }
};