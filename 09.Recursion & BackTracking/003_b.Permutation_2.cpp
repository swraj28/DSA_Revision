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

     The UpperBound Complexity can be assumed be to same as that of permutation 1

     It is Quite Difficult to comprehend the exact time complexity .

*/

class Solution {
public:
    vector<vector<int>> ans;
    void permute(vector<int>& nums, int n, int si) {
        if (si >= n) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;

        for (int i = si; i < n; i++) {

            if (s.find(nums[i]) != s.end()) {
                continue;
            }

            s.insert(nums[i]);
            swap(nums[i], nums[si]);
            permute(nums, n, si + 1);
            swap(nums[i], nums[si]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        permute(nums, n, 0);

        return ans;
    }
};