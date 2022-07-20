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

/*

    Total number of states is n and on every state we are making 2 calls either take or non-take.

    Therefore,the time Complexity is O(2^n).

    Auxiliary Space:- O(n)---> Recursive Stack Space.

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;

        vector<int> v;

        sub_set(nums, 0, result, v);

        return result;

    }

    void sub_set(vector<int>& nums, int si, vector<vector<int>>& result, vector<int> &v) {
        if (si == nums.size()) {
            result.push_back(v);
            return;
        }

        v.push_back(nums[si]);

        sub_set(nums, si + 1, result, v);

        v.pop_back();//backtrack

        sub_set(nums, si + 1, result, v);
    }
};