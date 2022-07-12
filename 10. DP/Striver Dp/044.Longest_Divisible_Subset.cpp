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

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(all(nums));

        vector<int> dp(n), pred(n, -1);
        dp[0] = 1;

        int mx_idx = 0;

        for (int i = 1; i < n; i++) { // Longest Divsible Subsequence Ending at index i.

            dp[i] = 1;

            for (int j = i - 1; j >= 0; j--) {

                if (nums[i] % nums[j]) {
                    continue;
                }

                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pred[i] = j;
                }
            }

            if (dp[i] > dp[mx_idx]) {
                mx_idx = i;
            }
        }

        vector<int> ans;

        for (; mx_idx >= 0; mx_idx = pred[mx_idx]) {
            ans.pb(nums[mx_idx]);
        }

        return ans;
    }
};