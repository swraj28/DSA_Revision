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

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<vector<int>> ans;

        int lft_extreme = intervals[0][0];
        int rgt_extreme = intervals[0][1];

        vector<int> v1;

        for (int i = 1; i < n; i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];

            if (left <= rgt_extreme) {
                rgt_extreme = max(rgt_extreme, right);
            } else {
                v1.clear();
                v1.push_back(lft_extreme);
                v1.push_back(rgt_extreme);

                ans.push_back(v1);

                lft_extreme = left;
                rgt_extreme = right;
            }
        }

        v1.clear();
        v1.push_back(lft_extreme);
        v1.push_back(rgt_extreme);

        ans.push_back(v1);

        return ans;
    }
};